/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Solver.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmenant <bmenant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:40:29 by bmenant           #+#    #+#             */
/*   Updated: 2022/01/07 15:25:16 by bmenant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Equation.h"
#include "../inc/Parser.h"
#include "../inc/Solver.h"
#include "../inc/computor.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

Solver::Solver(vector<double> coeff) : m_coeff(coeff)
{
}

double Solver::squareRoot(double X) 
{
    double A, B, M, XN;
    if (X == 0.0) 
        return 0.0;
    else
    {
        M = 1.0;
        XN = X;
        while(XN >= 2.0)
        {
            XN = 0.25 * XN;
            M = 2.0 * M;
        }
        while(XN < 0.5)
        {
            XN = 4.0 * XN;
            M = 0.5 * M;
        }
        A = XN;
        B = 1.0 - XN;
        do
        {
            A = A * (1.0 + 0.5 * B);
            B = 0.25 * (3.0 + B) * B * B;
        } while( B >= 1.0E-15);
        return (A * M);
    }
}

void Solver::showCoeff()
{
    cout << endl << "In Solver, Coeffs are :" << endl;
    for (int i(0); i < (int)m_coeff.size(); i++)
    {
        cout << "Coeff " << i << " : " << m_coeff[i] << endl;
    }
}

void Solver::solveNoDegree()
{
    cout << "The solution is: " << endl << "All real numbers." << endl;
}

void Solver::solveImpossible()
{
    cout << "With a little logic, you can see that this equation is impossible, there is no solution." 
    << endl << "Please rebuild your equation correctly." << endl;
}

void Solver::solveOneDegree()
{
    cout << "The solution is:" << endl << (-1) * (m_coeff[0] / m_coeff[1]) << endl; 
}

void Solver::solveCaseUp(double delta)
{
    double solutionA(0.0);
    double solutionB(0.0);

    solutionA = ((-1) * m_coeff[1] + squareRoot(delta)) / (2 * m_coeff[2]);
    solutionB = ((-1) * m_coeff[1] - squareRoot(delta)) / (2 * m_coeff[2]);
    cout << "Discriminant is strictly positive, the two solutions are:" << endl << solutionA << endl << solutionB << endl;
}

void Solver::solveCaseEqual()
{
    double solution (0.0);

    solution = ((-1) * m_coeff[1]) / (2 * m_coeff[2]);
    cout << "Discriminant is strictly null, the solution is:" << endl << solution << endl;
}

void Solver::solveCaseDown(double delta)
{
    double realSolution = ((-1) * m_coeff[1]) / (2 * m_coeff[2]);
    double unrealSolution = (squareRoot((-1) * delta)) / (2 * m_coeff[2]);
    cout << "Discriminant is strictly negative, the two solutions are:" << endl;
    if (unrealSolution < 0)
    {
        cout << realSolution << " - " << ((-1) * unrealSolution) << "i" << endl;
        cout << realSolution << " + " << ((-1) * unrealSolution) << "i" << endl;
    }
    else
    {
        cout << realSolution << " + " << (unrealSolution) << "i" << endl;
        cout << realSolution << " - " << (unrealSolution) << "i" << endl;
    }
}

void Solver::solveTwoDegree()
{
    double delta(0.0);

    delta = m_coeff[1] * m_coeff[1] - (4 * m_coeff[2] * m_coeff[0]);
    
    if (delta != 0)
        cout << "Discriminant isn't null, delta = " << delta << "." << endl;
    else
        cout << "Discriminant is null, delta = 0." << endl;

    if (delta > 0)
        solveCaseUp(delta);
    else if (delta == 0)
        solveCaseEqual();
    else if (delta < 0)
        solveCaseDown(delta);
}

void Solver::solveEquation()
{
    if (m_coeff[0] == 0.0 && m_coeff[1] == 0.0 && m_coeff[2] == 0.0 && m_coeff[3] == 0.0)
        solveNoDegree();
    else if (m_coeff[0] != 0.0 && m_coeff[1] == 0.0 && m_coeff[2] == 0.0 && m_coeff[3] == 0.0)
        solveImpossible();
    else if (m_coeff[1] != 0.0 && m_coeff[2] == 0.0 && m_coeff[3] == 0.0)
        solveOneDegree();
    else if (m_coeff[2] != 0.0 && m_coeff[3] == 0.0)
        solveTwoDegree();
}