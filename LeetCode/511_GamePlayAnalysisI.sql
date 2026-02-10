SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;

-- SELECT 
--     X.player_id,
--     X.event_date AS first_login
-- FROM 
-- (
--     SELECT 
--     player_id, 
--     event_date, 
--     RANK() OVER (
--         PARTITION BY player_id ORDER BY event_date
--     ) AS rnk
--     FROM Activity
-- ) X
-- WHERE X.rnk = 1;