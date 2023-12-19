import qbs.FileInfo

QtApplication {
    Depends { name: "Qt.core" }
    Depends { name: "factory" }
    Depends { name: "observer" }
    cpp.cxxLanguageVersion: ["c++17"]
    cpp.defines: [ "APPLICATION_LIBRARY" ]

    Group {
        name: "C++"
        files: [
            "*.h",
            "*.cpp"
        ]
    }

    install: true
    installDir: qbs.targetOS.contains("qnx") ? FileInfo.joinPaths("/tmp", name, "bin") : base
}
