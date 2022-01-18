/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParserSimplified.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 16:12:54 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/18 16:39:52 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_PARSERSIMPLIFIED
#define DEF_PARSERSIMPLIFIED

#include <string>
#include <vector>

class Parsersimplified
{
    public:

    Parsersimplified(std::string totalEquation);
    std::vector<std::string> getLeftOpe();
    std::vector<std::string> getRightOpe();
    bool equationInTwoTabs();
    void showTheEquation();
    int parseCheckX();
    int checkHandlerX(std::vector<std::string> tab);

    private:

    std::vector<std::string> m_leftOpe;
    std::vector<std::string> m_rightOpe;
    std::string m_totalEquation;
};

#endif