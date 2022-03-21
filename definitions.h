#ifndef GAME_DEFINITIONS_H
#define GAME_DEFINITIONS_H

#define TILE_SIZE 64


#define SingletonHeader(ClassName)                  \
public:                                             \
    ClassName(ClassName &) = delete;                \
    void operator=(const ClassName &) = delete;     \
    static ClassName* getInstance();                \
private:                                            \
    ClassName();                                    \
    ~ClassName();                                   \
    static ClassName* _instance;                    \


#define SingletonBody(ClassName)                    \
ClassName* ClassName::_instance = nullptr;          \
ClassName *ClassName::getInstance() {               \
    if (_instance == nullptr) {                     \
        _instance = new ClassName();                \
    }                                               \
    return _instance;                               \
}                                                   \

#define SafeDelete(p){ if(p){ delete (p); (p) = NULL; } }

#endif //GAME_DEFINITIONS_H
