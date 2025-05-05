-- Syntax for NVL
SELECT NVL(column, default_value) FROM table_name;

-- Syntax for UPPER, LOWER, INITCAP
SELECT UPPER(column) FROM table_name;
SELECT LOWER(column) FROM table_name;
SELECT INITCAP(column) FROM table_name;

-- Example
SELECT name, NVL(salary, 0) FROM Emp;
SELECT INITCAP(name) FROM Emp;
