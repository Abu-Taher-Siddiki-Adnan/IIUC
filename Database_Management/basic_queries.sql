-- Syntax for selecting all columns
SELECT * FROM table_name;

-- Syntax for selecting specific columns
SELECT column1, column2 FROM table_name;

-- Example
SELECT * FROM Emp;
SELECT name, position FROM Emp;

-- Syntax for filtering data using WHERE
SELECT column1, column2 FROM table_name WHERE condition;

-- Example
SELECT * FROM Emp WHERE salary < 20000;
