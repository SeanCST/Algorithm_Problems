# Write your MySQL query statement below

SELECT DISTINCT 
    a.email AS Email
FROM 
    Person a, Person b
WHERE 
    a.email = b.email and a.id != b.id