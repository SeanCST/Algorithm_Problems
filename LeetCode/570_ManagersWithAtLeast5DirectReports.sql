# Write your MySQL query statement below
-- WITH Directs AS (
--     SELECT managerId, count(*) AS directs
--     FROM Employee
--     WHERE managerId IS NOT NULL
--     GROUP BY managerId
-- ) 
-- SELECT name 
-- FROM Employee e JOIN Directs d
-- WHERE e.id = d.managerId 
--     AND d.directs >= 5;

SELECT name 
FROM Employee
WHERE id in (
    SELECT managerId from Employee
    GROUP BY managerId
    HAVING count(*) >= 5
);