Product {
    name: "factory"

    type: ["dynamiclibrary", "libsyms"]

    Depends { name: "Qt.core" }
    Depends { name: "cpp" }
    //cpp.cxxLanguageVersion: ["c++17"]
    cpp.defines: ['FACTORY_LIBRARY']

    Group {
        name: "C++"
        files: [
            "*.h",
            "*.cpp"
        ]
    }
}
