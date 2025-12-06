//
// Created by Catalin on 12/6/2025.
//

#ifndef OOP_EXCEPTIONS_H
#define OOP_EXCEPTIONS_H
#include <stdexcept>
#include <string>

class GameException: public std::runtime_error {
public:
    explicit GameException(const std::string& msg): std::runtime_error(msg){}
};
class StationException: public GameException {
public:
    explicit StationException(const std::string& msg): GameException("Station error: " + msg){}
};
class ActionException: public GameException {
public:
    explicit ActionException(const std::string& msg): GameException("Action error: " +msg){}
};
class ConfigException : public GameException {
public:
    explicit ConfigException(const std::string& msg)
        : GameException("Config error: " + msg) {}
};
#endif //OOP_EXCEPTIONS_H