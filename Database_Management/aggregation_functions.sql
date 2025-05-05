-- Syntax for aggregate functions
SELECT COUNT(column_name) FROM table_name;
SELECT SUM(column_name) FROM table_name;
SELECT AVG(column_name) FROM table_name;
SELECT MIN(column_name) FROM table_name;
SELECT MAX(column_name) FROM table_name;

-- Example
SELECT COUNT(*) AS TotalEmployee FROM Emp;
SELECT SUM(salary) AS TotalSalary FROM Emp;

