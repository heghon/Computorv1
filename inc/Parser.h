/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 18:44:48 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/18 16:07:11 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEF_PARSER
#define DEF_PARSER

#include <string>
#include <vector>

class Parser
{
    public:

    Parser(std::string totalEquation);
    std::vector<std::string> getLeftOpe();
    std::vector<std::string> getRightOpe();
    bool equationInTwoTabs();
    void showTheEquation();
    bool parseConstruct();
    bool parseOrder();
    int parseCheckX();
    int checkHandlerX(std::vector<std::string> tab);
    bool orderCheck(std::vector<std::string> tab);
    bool constructSide(std::vector<std::string> tab);

    private:

    std::vector<std::string> m_leftOpe;
    std::vector<std::string> m_rightOpe;
    std::string m_totalEquation;
};

#endif