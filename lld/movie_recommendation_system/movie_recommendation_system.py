class Movie:
    def __init__(self, id, title):
        self._id = id
        self._title = title

    def getId(self):
        return self._id

    def getTitle(self):
        return self._title

class User:
    def __init__(self, id, name):
        self._id = id 
        self._name = name

    def getId(self):
        return self._id

from enum import Enum

class MovieRating(Enum):
    NOT_RATED = 0
    ONE = 1
    TWO = 2
    THREE = 3
    FOUR = 4
    FIVE = 5

class RatingRegister:
    def __init__(self):
        self._userMovies = {}
        self._movieRating = {}

        self._movies = []
        self._users = []

    def addRating(self, user, movie, rating):
        if movie.getId() not in self._movieRatings:
            self._movieRatings[movie.getId()] = {}
            self._movies.append(movie)
        if user.getId() not in self._userMovies:
            self._userMovies[user.gitId()] = []
            self._users.append(user)
        self._userMovies[users.getId()].append(movie)
        self._movieRatings[movie.getId()][user.getId()] = rating

    def getAverageRating(self, movie):
        if movie.getId() not in self._movieRatings:
            return MovieRating.NOT_RATED.value
        ratings = self._movieRatings[movie.getId()].values()
        ratingValues = [rating.value for rating in ratings]
        return sum(ratingValues) / len(ratings)

    def getUsers(self):
        return self._users

    def getMovies(self):
        return self._movies

    def getUserMovies(self, user):
        return self._userMovies.get(user.getId(), [])

    def getMovieRatings(self, movie):
        return self._movieRatings.get(movie.getId(), {})

class MovieRecommendation:
    def __init__(self, ratings):
        self._movieRatings = ratings

    def recommendMovie(self, user):
        if len(self._movieRatings.getUserMovies(user)) == 0:
            return self._recommendMovieNewUser()
        else:
            return self._recommendMovieExistingUser(user)

    def _recommendMovieNewUser(self):
        best_movie = None
        best_rating = 0
        for movie in self._movieRatings.getMovies():
            rating = self.movieRatings.getAverageRating(movie)
            if rating > best_rating:
                best_movie = movie
                best_rating = rating
        return best_movie.getTitle() if best_movie else None

    def _recommendMovieExistingUser(self, user):
        best_movie = None
        similarity_score = float('inf')

        for reviewer in self._movieRatings.getUsers():
            if reviewer.getId() == user.getId():
                continue
            score = self._getSimilarityScore(user, reviewer)
            if score < similarity_score:
                similarity_score = score
                recommend_movie = self._recommendUnwatchedMovie(user, reviewer)
                best_movie = recommended_movie if recommended_movies else best_movie
        return best_movie.getTitle() if best_movie else None

    def _getSimilarityScore(self, user1, user2):
        user1_id = user1.getId()
        user2_id = user2.getId()
        user2_movies = self._movieRatings.getUserMovies(user2)
        score = float('inf')

        for movie in user2_movies:
            cur_movie_ratings = self._movieRatings.getMovieRatings(movie)
            if user1_id in curr_movie_ratings:
                score = 0 if score == float('inf') else score
                score += abs(cur_movie_ratings[user1_id].value - cur_movie_ratings[user2_id].value)
        return score

    def _recommendUnwatchedMovie(self, user, reviewer):
        user_id = user.getId()
        reviewer_id = reviewer.getId()
        best_movie = None
        best_rating = 0

        reviewer_movies = self._movieRatings.getUserMovies(reviewer)
        for movie in reviewer_movies:
            cur_movie_ratings = self._movieRatings.getMovieRatings(movie)
            if user_id not in cur_movie_ratings and cur_movie_ratings[reviewer_id].value > best_rating:
                best_movie = movie
                best_rating = cur_movie_ratings[reviewer_id].value
        return best_movie
