#Import InfluxDBClient library
from influxdb import InfluxDBClient

#influxdb settings
host='influx_server'
db='db_name' #replace by your database

#influxdb credentials
username='db_username' #replace by your database user login
password='db_password' #replace by your dabase user password



#init the influxdb client
client = InfluxDBClient(host=host, port=80, username=username, password=password, database=db) 

# Montre les database
client.get_list_database()

# On choisit notre database
client.switch_database('db_name')


# QUERY CREATION EXAMPLE ************************************************************************

#query = 'SELECT mean("Temperature") FROM "Mesure" WHERE time >= 1613471545851ms and time <= 1613772675577ms GROUP BY time(2m) fill(null)'
#query = 'SELECT mean("Rssi") FROM "Tests wifi" WHERE time >= 1613843875838ms and time <= 1613844603167ms GROUP BY time(500ms) fill(none)'

query='SELECT last(Rssi) as lastdata FROM "Tests wifi"'  # *********************MODIFIABLE*********************

rs = client.query(query)
print(rs)

#*******************************
#*******************************

# PRINTS VALUE AND TIME FROM QUERY
temperature_values = list(rs.get_points(measurement='Tests wifi')) # *********************MODIFIABLE*********************
for i in temperature_values:
    value = i.get('lastdata')
    print(value)
    temps = i.get('time')
    print(temps)
    print('\n')
