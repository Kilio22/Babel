/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** DatabaseProvider
*/

#ifndef DATABASEPROVIDER_HPP_
#define DATABASEPROVIDER_HPP_

#include "database/IDb.hpp"
#include <memory>
#include <type_traits>

namespace Babel::Server
{

    class DatabaseProvider {

    public:
        DatabaseProvider() = default;
        ~DatabaseProvider() = default;

        template <typename T>
        static IDb *getDb()
        {
            static_assert(std::is_base_of<IDb, T>::value, "T must extend list");
            static std::unique_ptr<IDb> instance = std::make_unique<T>();
            return instance.get();
        }
    };
} // namespace Babel::Server

#endif /* !DATABASEPROVIDER_HPP_ */
