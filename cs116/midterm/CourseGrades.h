/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CourseGrades.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikim <mikim@student.42.us.org>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 14:05:39 by mikim             #+#    #+#             */
/*   Updated: 2018/03/29 15:17:48 by mikim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Mingyun Kim
**	https://www.github.com/mikim42
*/

#ifndef COURSE_GRADES_H
# define COURSE_GRADES_H

# include <iostream>
# include <string>

using namespace std;

struct		GradedActivity
{
	int		score;
	char	grade;
};

struct		PassFailExam
{
	int		score;
};

struct		Essay
{
	int		score;
};

struct		FinalExam
{
	int		score;
};

class		CourseGrades
{
	private:
		GradedActivity	*grades[4];

	public:
		CourseGrades(void);
		void	setLab(GradedActivity *grade);
		void	setPassFailExam(PassFailExam *exam);
		void	setEssay(Essay *essay);
		void	setPassFailExam(FinalExam *fin);
		void	print(void);
};

#endif
