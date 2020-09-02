--list the names of all people who starred in Toy Story.
SELECT name
FROM people
WHERE people.id IN
(SELECT stars.person_id
	FROM stars
	JOIN movies
	ON stars.movie_id = movies.id
	WHERE title = "Toy Story");
