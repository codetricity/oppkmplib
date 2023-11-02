plugins {
    kotlin("multiplatform") version "1.9.20"
}

repositories {
    mavenCentral()
}

kotlin {
        mingwX64("native") { // on Windows
        binaries {
            sharedLib {
                 baseName = "libnative" // on Windows
            }
        }
    }
}

tasks.wrapper {
    gradleVersion = "8.1.1"
    distributionType = Wrapper.DistributionType.ALL
}