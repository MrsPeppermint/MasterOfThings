-- list the names of all people who starred in a movie released in 2004, ordered by birth year.
--If a person appeared in more than one movie in 2004, they should only appear in your results once.*/
SELECT name
FROM people
WHERE people.id IN
(SELECT DISTINCT stars.person_id
FROM stars
JOIN movies
ON movies.id = stars.movie_id
WHERE year = 2004)
ORDER BY (people.birth) ASC;
