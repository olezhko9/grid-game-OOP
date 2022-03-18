#ifndef GAME_DEFINITIONS_H
#define GAME_DEFINITIONS_H

#define TILE_SIZE 60


#define SingletonHeader(ClassName)                  \
public:                                             \
    ClassName(ClassName &) = delete;                \
    void operator=(const ClassName &) = delete;     \
    static ClassName* getInstance();                \
    static void Create();                           \
    static void Delete();                           \
private:                                            \
    ClassName() = default;                          \
    ~ClassName();                                   \
    static ClassName* _instance;


#define SingletonBody(ClassName)                    \
ClassName* ClassName::_instance = nullptr;          \
ResourcesManager *ResourcesManager::getInstance() { \
    if (_instance == nullptr) {                     \
        _instance = new ResourcesManager();         \
    }                                               \
    return _instance;                               \
}

#endif //GAME_DEFINITIONS_H
