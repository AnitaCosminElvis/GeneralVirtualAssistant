plugins {
    kotlin("multiplatform") version "1.4.32"
}

group = "me.selectuls"
version = "1.0-SNAPSHOT"

repositories {
    mavenCentral()
}

kotlin {
        //linuxX64("native") {  // on Linux
        // macosX64("native") { // on macOS
        mingwX64("native") { //on Windows
        binaries {
            sharedLib {
                //baseName = "native" // on Linux and macOS
                baseName = "libnative" //on Windows
            }
        }
    }
}

tasks.wrapper {
    gradleVersion = "6.7.1"
    distributionType = Wrapper.DistributionType.ALL
}
