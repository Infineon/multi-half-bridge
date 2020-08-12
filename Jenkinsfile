/*
 * ##################################################################################
 * #
 * # Attention: this file is used for compilation checks together with
 * # Jenkins, SonarQube and OpenShift cluster
 * #
 */
pipeline {
	agent {
		node {
			label 'x64 || rpi'
			customWorkspace "/home/jenkins/Arduino/libraries/Tle94112"
		}
	}

	options {
		buildDiscarder(
			logRotator(
				numToKeepStr: '5',
				artifactNumToKeepStr: '5'
			)
		)
		disableConcurrentBuilds()
	}

	/*
	triggers {
		cron('H H(0-1) * * *')
	}
	*/

	stages {
		stage('Build documentation') {
			parallel {
				/*-----------------------------------------------------------------------------
				 * html
				 *-----------------------------------------------------------------------------
				 */
				stage('HTML') {
					steps {
						echo "html"
						sh ("export DOXY_BIN_PATH=/usr/local/bin/;cd ${env.WORKSPACE}/docs;/usr/bin/make html")
					}
				}
				/*-----------------------------------------------------------------------------
				 * latex/pdf
				 *-----------------------------------------------------------------------------
				 */
				stage('PDF') {
					steps {
						echo "latex/pdf"
						/*
						sh ("export DOXY_BIN_PATH=/usr/local/bin/;cd ${env.WORKSPACE}/docs;/usr/bin/make pdf")
						build(
							job: 'dev/doxy_maker_pdf',
							propagate: true,
							parameters: [
								[
									$class: 'StringParameterValue',
									name: 'WORKSPACE',
									value: "${env.WORKSPACE}"
								],
							]
						)
						*/
					}
				}
			} // end parallel
		} // end docu build

		stage('Check') {
			parallel {

				/*-----------------------------------------------------------------------------
				 * cppcheck
				 *-----------------------------------------------------------------------------
				 */
				stage('CPP') {
					steps {
						sh "cd  ${env.WORKSPACE};mkdir -p build;/usr/local/bin/cppcheck -v --enable=all --xml-version=2 -I examples src 2> build/cppcheck-report.xml"
					} // end steps
				} // end stage

				/*-----------------------------------------------------------------------------
				 * cppcheck
				 *-----------------------------------------------------------------------------
				 */
				stage('CLI') {
					steps {
						echo "Compile"
						sh ("cd ${env.WORKSPACE};/usr/bin/make all")
					} // end steps
				} // end stage

			} // parallel
		} // end stage

		stage('SonarQube') {
			environment {
				scannerHome = tool 'SonarQubeScanner'
			}
			steps {
				withSonarQubeEnv('SonarQube') {
					sh "${scannerHome}/bin/sonar-scanner -X"
				}
				catchError(buildResult: 'SUCCESS', stageResult: 'FAILURE') {
					timeout(time: 10, unit: 'MINUTES') {
						waitForQualityGate abortPipeline: true
					}
				}
			} // end steps
		} // end stage

		stage('Deploy') {
			parallel {
				/*-----------------------------------------------------------------------------
				 * development
				 *-----------------------------------------------------------------------------
				 */
				stage('Docu') {
					steps {
						echo "html deploy"
						sh("mkdir -p /mnt/raspel/Public/doxygen/Tle94112/;cd ${env.WORKSPACE}/docs;cp -r html /mnt/raspel/Public/doxygen/Tle94112/;")
					}
				}


				/*-----------------------------------------------------------------------------
				 * production
				 *-----------------------------------------------------------------------------
				 */
				stage('PRODUCTION') {
					steps {
						echo "Production"
					}
				}

			} // end parallel
		} // end stage
	} // end stages

	/*-----------------------------------------------------------------------------
	 * post
	 *-----------------------------------------------------------------------------
	 */
	post {
		failure {
			/*
			mail(
				to: '',
				subject: "[EPE JENKINS] ${IFXLIB} pipeline:",
				body: "Something during Jenkins pipeline run went wrong."
			)
			*/
		}
	}

}
