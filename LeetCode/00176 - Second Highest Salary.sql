# Write your MySQL query statement below
SELECT MAX(Salary) as SecondHighestSalary from Employee
WHERE Salary<(SELECT MAX(Salary) From Employee)
