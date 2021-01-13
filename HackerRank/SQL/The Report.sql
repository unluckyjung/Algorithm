SELECT IF(Grade >= 8, Students.NAME, NULL), Grades.Grade, Students.Marks
FROM Students, Grades
WHERE Students.Marks BETWEEN Grades.Min_Mark AND Grades.MAX_Mark
ORDER BY Grades.Grade DESC, Students.NAME ASC;