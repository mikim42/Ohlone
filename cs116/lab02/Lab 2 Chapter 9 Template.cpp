/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lab 2 Chapter 9 Template.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Mingyun Kim <mikim@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 14:26:26 by Mingyun K         #+#    #+#             */
/*   Updated: 2018/02/05 16:46:53 by Mingyun K        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
 
using namespace std;

const int NO_OF_STUDENTS = 20;

struct		studentType
{
    string	studentFName;
    string	studentLName;
    int		testScore;
    char	grade;
};

void	getData(ifstream& inFile, studentType sList[], int listSize);
void	calculateGrade(studentType sList[], int listSize);
int		highestScore(const studentType sList[], int listSize);
void	printResult(ofstream& outFile, const studentType sList[], int listSize);

int		main()
{
    ifstream	inData;
    ofstream	outData;
    studentType	studentList[NO_OF_STUDENTS];

	// Open input file
    inData.open("Ch9_Ex2Data.txt");
    if (!inData)
    {
        cout << "The input file does not exist. Program terminates!" << endl;
        return 1;
    }

	// Open output file
    outData.open("Ch9_Ex2Out.txt");
    if (!outData)
    {
        cout << "Cannot open the output file. Program terminates!" << endl;
        return 1;
    }

	getData(inData, studentList, NO_OF_STUDENTS);
	calculateGrade(studentList, NO_OF_STUDENTS);
	printResult(outData, studentList, NO_OF_STUDENTS);
    return 0;
}

void	getData(ifstream& inFile, studentType sList[], int listSize)
{
	for (int i = 0; i < listSize; i++){
		inFile >> sList[i].studentFName;
		inFile >> sList[i].studentLName;
		inFile >> sList[i].testScore;
	}
}

void	calculateGrade(studentType sList[], int listSize)
{
	for (int i = 0; i < listSize; i++){
		if (sList[i].testScore >= 90)
			sList[i].grade = 'A';
		else if (sList[i].testScore >= 80)
			sList[i].grade = 'B';
		else if (sList[i].testScore >= 70)
			sList[i].grade = 'C';
		else
			sList[i].grade = 'F';
	}
}

int		highestScore(const studentType sList[], int listSize)
{
    int hScore = sList[0].testScore;

	for (int i = 0; i < listSize; i++){
		if (hScore < sList[i].testScore)
			hScore = sList[i].testScore;
	}
    return hScore;
}

void	printResult(ofstream& outFile, const studentType sList[], int listSize)
{
	size_t	width = 0;
	
	for (int i = 0; i < listSize; i++){
		if (width < sList[i].studentFName.length() +
											sList[i].studentLName.length() + 3)
			width = sList[i].studentFName.length() +
											sList[i].studentLName.length() + 3;
	}

	outFile << setw(width) << left << "Student Name"
			<< "   Test Score   Grade" << endl;
	for (int i = 0; i < listSize; i++){
		outFile << setw(width) << left
				<< sList[i].studentLName + ", " +
				   sList[i].studentFName;
		outFile << "   " << right << setw(10) << sList[i].testScore << "   "
				<< setw(5) << sList[i].grade
				<< endl;
	}
	outFile << endl;

	int highest = highestScore(sList, NO_OF_STUDENTS);

	outFile << "Highest Test Score: " << highest << endl
			<< "Students having the highest test score:" << endl;
	for (int i = 0; i < listSize; i++){
		if (sList[i].testScore == highest){
			outFile << sList[i].studentLName + ",  "
					<< sList[i].studentFName << endl;
		}
	}
}
