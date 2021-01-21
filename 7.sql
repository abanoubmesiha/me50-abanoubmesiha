SELECT title, rating
FROM movies JOIN rating ON movies.id = ratings.movie_id
WHERE year = 2010
ORDER BY rating DESC, title ASC;