-- Syntax for creating a table
CREATE TABLE table_name (
    column1 datatype constraint,
    column2 datatype constraint,
    ...
);

-- Syntax for inserting data into a table
INSERT INTO table_name (column1, column2, ...) VALUES (value1, value2, ...);

-- Example
CREATE TABLE Emp (
    empID INT PRIMARY KEY,
    name VARCHAR2(50),
    salary INT,
    position VARCHAR2(10)
);

INSERT INTO Emp(empID, name, salary, position)
VALUES (101, 'Ramij Uddin', 10000, 'Peon');

INSERT INTO Emp(empID, name, salary, position)
VALUES (102, 'Kashem', 15000, 'Manager');
