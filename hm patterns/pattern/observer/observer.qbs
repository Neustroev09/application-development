Product {
    name: "observer"

    type: ["dynamiclibrary", "libsyms"]

    Depends { name: "Qt.core" }
    Depends { name: "cpp" }
    //cpp.cxxLanguageVersion: ["c++17"]
    cpp.defines: ['OBSERVER_LIBRARY']

    Group {
        name: "C++"
        files: [
            "*.h",
            "*.cpp"
        ]
    }
}
