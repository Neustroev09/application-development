import qbs

Project {
    references: {
        var s = [
                    'factory/factory.qbs',
                    'observer/observer.qbs',
                    'application/application.qbs',
                ];
        return s;
    }
}
