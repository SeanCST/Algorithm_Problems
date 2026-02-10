WITH Temp 
AS (
    SELECT candidateId, count(*) AS votes
    FROM Vote
    GROUP BY candidateId
    ORDER BY votes DESC
    LIMIT 1
)
SELECT name 
FROM Candidate INNER JOIN Temp
WHERE Candidate.id = Temp.candidateId;