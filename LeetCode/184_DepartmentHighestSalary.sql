# Write your MySQL query statement below
WITH EmployeeRanks AS (
    SELECT
        e.name, 
        e.salary, 
        d.name AS departmentName,
        RANK() OVER(
            PARTITION BY e.departmentId
            ORDER BY e.salary DESC
        ) AS salaryRank
    FROM Employee e JOIN Department d 
    ON e.departmentId = d.id
)
SELECT
    departmentName AS Department,
    name AS Employee,
    salary AS Salary
FROM EmployeeRanks
WHERE salaryRank = 1;