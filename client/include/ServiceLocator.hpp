/*
** EPITECH PROJECT, 2020
** B-CPP-500-REN-5-1-babel-kylian.balan
** File description:
** ServiceLocator
*/

#ifndef SERVICELOCATOR_HPP_
#define SERVICELOCATOR_HPP_

namespace Babel::Client
{
    /**
     * @brief Service Locator Design Pattern.
     * 
     */
    class ServiceLocator
    {
    private:
        ServiceLocator() = default;

    public:
        ServiceLocator(const ServiceLocator &) = delete;
        ~ServiceLocator() = default;
        ServiceLocator &operator=(const ServiceLocator &) = delete;

        /**
         * @brief Get Service Locator Singleton Instance.
         * 
         * @return ServiceLocator& 
         */
        static ServiceLocator &getInstance()
        {
            static ServiceLocator serviceLocator;

            return serviceLocator;
        }

        /**
         * @brief Get a singleton instance of an object stored in the service locator.
         * 
         * @tparam T Type of the Object.
         * @return T& A reference to the object.
         */
        template <typename T>
        T &get()
        {
            static T service;

            return service;
        }
    };
};

#endif /* !SERVICELOCATOR_HPP_ */
