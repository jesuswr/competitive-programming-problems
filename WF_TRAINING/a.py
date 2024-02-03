# given a latitude and longitude, validate that the values of each is correct
# -90 <= latitude <= 90 
# -180 <= long <= 180

# def validate_lat_and_long(lat, long):
#     if lat < -90 or lat > 90:
#         raise Exception("Not valid latitude " + str(lat))
#     if long < -180 or long > 180:
#         raise Exception("Not valid longitude " + str(long))
#     return True

# def test_good_values():
#     try:
#         answer = validate_lat_and_long(10, 30)
#         print('worked!')
#     except e:
#         print(e)

# def test_wrong_values():
#     try:
#         answer = validate_lat_and_long(10, 3130)
#         print('worked!')
#     except Exception as e:
#         print(e)
    
# test_good_values()
# test_wrong_values()



# given a datetime, check if the day is the same as the hour
# from datetime import datetime

# def check_day_and_hour_equals():
#     date_obj = datetime.now()
#     return date_obj.day == date_obj.hour

# class A:
#     v = 0
#     def f():
#         v += 1
#         return 132


# A.f()

# index a,b,c
# a,b,c



# postgres, mysql
# mongo, elasticsearch



# assets (asset_id, price, city)
# cities (name, population)

# all assets that dont belong to a city
# we want to know that dont belong to a city with a population less than 1 million

# SELECT a.asset_id
# FROM assets a
# LEFT JOIN cities c ON a.city = c.name
# WHERE population >= 1000000


# videos
# video_id, views, titles, channel_id, channel_subs, channel_countries


# s3, athena, airflow, cloudwatch, opensearch, kibana


