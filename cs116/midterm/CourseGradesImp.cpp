/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseGradesImp.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:05:47 by mikim             #+#    #+#             */
/*   Updated: 2018/03/29 15:15:26 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#include "CourseGrades.h"

CourseGrades::CourseGrades(void)
{
	for (int i = 0; i < 4; i++)
	{
		grades[i] = new GradedActivity;
	}
}

void	CourseGrades::setLab(GradedActivity *grade)
{
	grades[0]->score = grade->score;
	if (grades[0]->score >= 90)
		grades[0]->grade = 'A';
	else if (grades[0]->score >= 80)
		grades[0]->grade = 'B';
	else if (grades[0]->score >= 70)
		grades[0]->grade = 'C';
	else
		grades[0]->grade = 'F';
}

void	CourseGrades::setPassFailExam(PassFailExam *exam)
{
	grades[1]->score = exam->score;
	if (grades[1]->score >= 90)
		grades[1]->grade = 'A';
	else if (grades[1]->score >= 80)
		grades[1]->grade = 'B';
	else if (grades[1]->score >= 70)
		grades[1]->grade = 'C';
	else
		grades[1]->grade = 'F';
}

void	CourseGrades::setEssay(Essay *essay)
{
	grades[2]->score = essay->score;
	if (grades[2]->score >= 90)
		grades[2]->grade = 'A';
	else if (grades[2]->score >= 80)
		grades[2]->grade = 'B';
	else if (grades[2]->score >= 70)
		grades[2]->grade = 'C';
	else
		grades[2]->grade = 'F';
}

void	CourseGrades::setPassFailExam(FinalExam *fin)
{
	grades[3]->score = fin->score;
	if (grades[3]->score >= 90)
		grades[3]->grade = 'A';
	else if (grades[3]->score >= 80)
		grades[3]->grade = 'B';
	else if (grades[3]->score >= 70)
		grades[3]->grade = 'C';
	else
		grades[3]->grade = 'F';
}

void	CourseGrades::print(void)
{
	cout 
	<< "Lab activity: " << grades[0]->score << ", " << grades[0]->grade << endl
	<< "Exam: " << grades[1]->score << ", " << grades[0]->grade<< endl
	<< "Essay: " << grades[2]->score << ", " << grades[0]->grade<< endl
	<< "Final Exam: " << grades[3]->score << ", " << grades[0]->grade<< endl;
}
