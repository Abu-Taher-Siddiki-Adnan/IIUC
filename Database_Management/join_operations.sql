-- Syntax for INNER JOIN
SELECT * FROM table1 INNER JOIN table2 ON table1.column = table2.column;

-- Syntax for NATURAL JOIN
SELECT * FROM table1 NATURAL JOIN table2;

-- Example
SELECT * FROM Emp INNER JOIN dept ON Emp.empID = dept.empID;
SELECT * FROM Emp NATURAL JOIN dept;
