import qbs

CppApplication {
    consoleApplication: true
    files: [
        "HomeMadeFunction.cpp",
        "HomeMadeFunction.h",
        "README.md",
        "Tennis.cpp",
        "Tennis.h",
        "main.cpp",
    ]

    Group {     // Properties for the produced executable
        fileTagsFilter: "application"
        qbs.install: true
        qbs.installDir: "bin"
    }
}
