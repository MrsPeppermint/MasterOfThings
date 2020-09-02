-- list titles of movies released on or after 2018 alphabetically

SELECT title 
FROM movies
WHERE year >= 2018
ORDER BY title ASC;
