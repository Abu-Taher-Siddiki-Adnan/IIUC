-- Syntax for GROUP BY
SELECT column1, aggregate_function(column2)
FROM table_name
GROUP BY column1;

-- Syntax for HAVING
SELECT column1, aggregate_function(column2)
FROM table_name
GROUP BY column1
HAVING condition;

-- Example
SELECT position, SUM(salary) AS TotalSalary
FROM Emp
GROUP BY position
HAVING SUM(salary) > 15000;
