-- Syntax for STDDEV and VARIANCE
SELECT STDDEV(column_name) FROM table_name;
SELECT VARIANCE(column_name) FROM table_name;

-- Example
SELECT STDDEV(salary) AS SalaryStandardDeviation FROM Emp;
SELECT VARIANCE(salary) AS SalaryVariance FROM Emp;
