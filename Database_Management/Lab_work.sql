-- Creating the 'Emp' table with empID, name, salary, and position columns.
create table Emp(
         empID int primary key,  -- empID as primary key
         name varchar2(50),      -- name of the employee
         salary int,             -- salary of the employee
         position varchar2(10)   -- position of the employee
); 

-- Inserting sample records into the 'Emp' table.
insert into Emp(empID,name,salary,position) 
values (101,'Ramij Uddin', 10000, 'Peon');  -- Employee 1
insert into Emp(empID,name,salary,position) 
values(102,'Kashem',15000,'Manager');        -- Employee 2
insert into Emp(empID,name,salary,position) 
values(103,'Selim Khan', 20000,'Accountant'); -- Employee 3
insert into Emp(empID,name,salary,position) 
values(105,'Salman khan', 30000,'Director');  -- Employee 4

-- Selecting all records from the 'Emp' table.
select * from Emp;

-- Selecting only 'name' column from the 'Emp' table.
select name from Emp;

-- Selecting records where salary is less than 20000.
select * from Emp where salary < 20000;

-- Selecting empID and name of employees whose salary is greater than 10000.
select empID, name from Emp where salary > 10000;

-- Sorting employees by salary in descending order.
select name, position, salary from Emp order by salary desc;

-- Using NVL function to replace NULL salary with 0 if salary is NULL.
select Name, NVL(Salary, 0) FROM Emp;

-- Using NVL2 function: If salary is not NULL, show 'Has Salary', otherwise 'No Salary'.
select Name, NVL2(Salary, 'Has Salary', 'No Salary') AS SalaryStatus FROM Emp;

-- Converting employee names to uppercase.
select upper(name) from Emp;

-- Converting employee names to InitCap (first letter of each word capitalized).
select initcap(name) from Emp;

-- Finding the length of each employee's name.
select name, LENGTH(Name) as NameLength from Emp;

-- Extracting the first 3 characters from employee names using SUBSTR.
select name, substr(name,1,3) from Emp;

-- Left padding the name with '*' to make the name length 15 characters.
select lpad(name,15,'*') from Emp;

-- Right padding the name with '$' to make the name length 15 characters.
select rpad(name,15,'$') from Emp;

-- Using TRIM function to remove any leading or trailing 'A' characters from the position.
select empID, name, trim('A' from position) from Emp;

-- Replacing all occurrences of 'a' in position with '@'.
select name, replace(position, 'a', '@') from Emp;

-- Creating the 'dept' table with empID and deptName columns.
create table dept(
         empID int primary key,  -- empID as primary key
         deptName varchar2(15)   -- department name
);

-- Inserting records into the 'dept' table.
insert into dept(empID, deptName)
values (101, 'HR');  -- Department 1
insert into dept(empID, deptName)
values(102, 'IT');   -- Department 2
insert into dept(empID, deptName)
values(103, 'Finance'); -- Department 3
insert into dept(empID, deptName)
values(104, 'Management'); -- Department 4

-- Performing an INNER JOIN between 'Emp' and 'dept' tables based on empID.
select * from Emp inner join dept on Emp.empID = dept.empID;

-- Performing a NATURAL JOIN between 'Emp' and 'dept' tables (implicitly matching columns with same names).
select * from Emp natural join dept;

-- Performing a LEFT JOIN to get all records from 'Emp' and matching records from 'dept'.
select * from Emp left join dept on Emp.empID = dept.empID;

-- Performing a RIGHT JOIN to get all records from 'dept' and matching records from 'Emp'.
select * from Emp right join dept on Emp.empID = dept.empID;

-- Performing a FULL OUTER JOIN to get all records from both 'Emp' and 'dept'.
select * from Emp full outer join dept on Emp.empID = dept.empID;

-- Counting the total number of employees in the 'Emp' table.
select count(*) as TotalEmployee from Emp;

-- Counting employees by their positions.
select position, count(*) as EmployeeCount from Emp group by position;

-- Calculating the total salary of all employees in the 'Emp' table.
select sum(salary) as Totalsalary from Emp;

-- Calculating the total salary by position.
select position, sum(salary) as totalsalary from Emp group by position;

-- Calculating the total salary by position, but only for positions where the total salary is greater than 15000.
select position, sum(salary) as totalsalary from Emp group by position having sum(salary) > 15000;

-- Calculating the average salary of employees in the 'Emp' table.
select avg(salary) as averagesalary from Emp;

-- Calculating the average salary by position.
select position, avg(salary) as averagesalary from Emp group by position;

-- Finding the minimum salary in the 'Emp' table.
select min(salary) as MinimumSalary from Emp;

-- Finding the minimum salary by position.
select position, min(salary) as MinimumSalary from Emp group by position;

-- Finding the maximum salary in the 'Emp' table.
select max(salary) as MaxiimumSalary from Emp;

-- Finding the maximum salary by position.
select position, max(salary) as MaxiimumSalary from Emp group by position;

-- Calculating the standard deviation of salaries in the 'Emp' table.
select STDDEV(salary) as SalaryStandardDeviation from Emp;

-- Calculating the variance of salaries in the 'Emp' table.
select VARIANCE(salary) AS SalaryVariance from Emp;
