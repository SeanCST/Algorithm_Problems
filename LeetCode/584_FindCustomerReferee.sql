# Write your MySQL query statement below
SELECT name 
FROM Customer
-- WHERE referee_id is NULL OR referee_id != 2;
WHERE IFNULL(referee_id, 0) != 2;