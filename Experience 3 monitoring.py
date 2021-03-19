 #Import InfluxDBClient library
from influxdb import InfluxDBClient

 #influxdb settings
host='DB_URL'
db='DB_name' #replace by your database

#influxdb credentials
username='DB_name' #replace by your database user login
password='DB_password' #replace by your dabase user password

 #init the influxdb client
client = InfluxDBClient(host=host, port=80, username=username, password=password, database=db) 


# Montre les database
client.get_list_database()

# On choisit notre database
client.switch_database('DB_NAME')

#******************************************************************************
#******************************************************************************

# MAIN CODE

import smtplib
server = smtplib.SMTP_SSL("smtp.gmail.com",465)
server.login("blabla@gmail.com","MAIL_PASSWORD")

#EMAIL EXAMPLE**********************************

#subject = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

#msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + " ans est de " + str(taux[i]) + ", sa temperature s'aggrave et est de" + str(t) + "C et "+ str(prenom) +" vient de tousser."

#message = 'Subject: {}\n\n{}'.format(subject, msg)

#reciever = 'blabla@gmail.com'

#server.sendmail("blabla@gmail.com", reciever, message)


import time

loop = True

#TEMPERATURE*************************************
# m lists are for temperature
# count_**** are for temperature too

m_first = [] # FIRST CONDITION
count_first = 0  # FIRST CONDITION

m_second = [] # SECOND CONDITION
count_second = 0 # SECOND CONDITION

m_third = [] # THIRD CONDITION
count_third = 0 # THIRD CONDITION

m_fourth = [] # FOURTH CONDITION
count_fourth = 0 # FOURTH CONDITION

m_fifth = [] # FIFTH CONDITION
count_fifth = 0 # FIFTH CONDITION

#BATTERY*******************************************
# p lists are for battery
# counter are for battery too

p_first = [] # FIRST CONDITION
counter_first = 0 # FIRST CONDITION

p_second = [] # SECOND CONDITION
counter_second = 0 # SECOND CONDITION

p_third = [] # THIRD CONDITION
counter_third = 0 # THIRD CONDITION

#OTHER*********************************************
# o lists are for other alerts

o_first = [1,2]

reciever = 'blabla@gmail.com'

while loop:
    
    #Temperature data
    query='SELECT last(Temperature) as lastdata FROM "Experience 2"' 
    rs = client.query(query)
    temperature_values = list(rs.get_points(measurement='Experience 2')) # *********************MODIFIABLE*********************
    
    #Battery data
    query='SELECT last(Niveau_de_batterie) as lastdata FROM "Experience 2"'
    rs = client.query(query)
    battery_values = list(rs.get_points(measurement='Experience 2')) # *********************MODIFIABLE*********************
    
    
    
    #Beginning anylising temperature
    for i in temperature_values:   #replace temperature_values by i if necessary
        current_temperature = i.get('lastdata')
        #print(value)
        current_time = i.get('time')
        #print(temps)
        #print('\n')
    
    #Beginning anylising battery level
    for j in battery_values:
        current_battery = j.get('lastdata')
        #current time is the same
    
    
    
    # FIRST CONDITION
    if current_temperature > 38 and current_temperature < 38.4: # Adapatation selon simu n'importe quel âge
        
        count_second = 0 # SECOND CONDITION
        m_second = [] # SECOND CONDITION
        
        count_third = 0 # THIRD CONDITION
        m_third = []    # THIRD CONDITION
        
        count_fourth = 0 # FOURTH CONDITION
        m_fourth = []    # FOURTH CONDITION
        
        m_fifth = []    # FIFTH CONDITION
        count_fifth = 0 # FIFTH CONDITION
        
        count_first +=1 # FIRST CONDITION
        m_first.append(current_temperature)
        
        if count_first ==1 : # si 4 valeurs d'affilé
            
            #ENVOI DE MAIL  APPARITION DE FIEVRE
            
            subject = "Appartition d'une fievre"

            msg = "La temperature de 887755 est actuellement de" + str(current_temperature) + "C", "c'est le debut d'une fievre."

            message = 'Subject: {}\n\n{}'.format(subject, msg)

            #reciever = 'blabla@gmail.com'

            server.sendmail("blabla@gmail.com", reciever, message)
            
            
            m_first=[]
            count_first = 0

            
            
    # SECOND CONDITION
    elif current_temperature >= 38.4 and current_temperature < 43: # Adapatation selon simu   n'importe qui
        
        count_first = 0 # FIRST CONDITION
        m_first = []    # FIRST CONDITION
        
        count_third = 0 # THIRD CONDITION
        m_third = []    # THIRD CONDITION
        
        count_fourth = 0 # FOURTH CONDITION
        m_fourth = []    # FOURTH CONDITION
        
        m_fifth = []    # FIFTH CONDITION
        count_fifth = 0 # FIFTH CONDITION
        
        count_second +=1
        m_second.append(current_temperature)
        if count_second == 1: # si 4 valeurs d'affilé
            
            
            #ENVOI DE MAIL AGGRAVATION FIEVRE
            
            subject = "Aggravation de la fievre"

            msg = "La temperature de 887755 est actuellement de" + str(current_temperature) + "C", "la fievre s'est aggravee."

            message = 'Subject: {}\n\n{}'.format(subject, msg)

            #reciever = 'blabla@gmail.com'

            server.sendmail("blabla@gmail.com", reciever, message)
            
            m_second = []
            count_second = 0
        
    # THIRD CONDITION
    elif current_temperature > 30 and current_temperature < 35:
        
        
        count_first = 0 # FIRST CONDITION
        m_first = []    # FIRST CONDITION
        
        count_second = 0 # SECOND CONDITION
        m_second = []    # SECOND CONDITION
        
        count_fourth = 0 # FOURTH CONDITION
        m_fourth = []    # FOURTH CONDITION
        
        m_fifth = []    # FIFTH CONDITION
        count_fifth = 0 # FIFTH CONDITION
        
        count_third+=1
        m_third.append(current_temperature)
        if count_second == 1: # si 3 valeurs d'affilé
            
            #ENVOI DE MAIL Donnée anormal
            
            subject = "Donnee anormale"

            msg = "La temperature de 887755 est actuellement de" + str(current_temperature) + "C", "ces donnees sont anormales."+"\n"+"Veuillez contacter votre medecin."

            message = 'Subject: {}\n\n{}'.format(subject, msg)

            #reciever = 'blabla@gmail.com'

            server.sendmail("blabla@gmail.com", reciever, message)
            
            count_third = 0
            m_third = []
    
    # FOURTH CONDITION
    elif current_temperature > 15 or current_temperature < 30:
        
        count_first = 0 # FIRST CONDITION
        m_first = []    # FIRST CONDITION
        
        count_second = 0 # SECOND CONDITION
        m_second = []    # SECOND CONDITION
        
        count_third = 0 # THIRD CONDITION
        m_third = []    # THIRD CONDITION
        
        m_fifth = []    # FIFTH CONDITION
        count_fifth = 0 # FIFTH CONDITION
        
        count_fourth+=1
        m_fourth.append(current_temperature)
        if count_fourth ==1: #si 4 valeurs d'affilé
            
            #ENVOI DE MAIL DISPOSITIF RETIRE
            
            subject = 'Dispositif retire'

            msg = 'La temperature mesuree est actuellement de ' + str(current_temperature) + 'C, ' + 'le dispositif a ete retire.'

            message = 'Subject: {}\n\n{}'.format(subject, msg)

            #reciever = 'blabla@gmail.com'

            server.sendmail("blabla@gmail.com", reciever, message)
            
            count_fourth = 0
            m_fourth = []
            
    # FIFTH CONDITION
    else:
        count_first = 0 # FIRST CONDITION
        m_first = []    # FIRST CONDITION
        
        count_second = 0 # SECOND CONDITION
        m_second = []    # SECOND CONDITION
        
        count_third = 0 # THIRD CONDITION
        m_third = []    # THIRD CONDITION
        
        count_fourth = 0 # FOURTH CONDITION
        m_fourth = []    # FOURTH CONDITION
        
        count_fifth+=1
        m_fifth.append(current_temperature)
        if count_fifth ==1: #si 3 valeurs
            
            #ENVOI DE MAIL DONNEES ABERRANTES
            
            subject = "Donnees aberrantes"

            msg = "La temperature mesuree est actuellement de" + str(current_temperature) + "C", "veuillez verifier la position du capteur de temperature."

            message = 'Subject: {}\n\n{}'.format(subject, msg)

            #reciever = 'blabla@gmail.com'

            server.sendmail("blabla@gmail.com", reciever, message)
            
            count_fifth = 0
            m_fifth = []
    
    
    #BATTERY
    
    # FIRST CONDITION
    if current_battery < 3.9 and current_battery >3.7:
        
        counter_second = 0 # SECOND CONDITION
        p_second = []      # SECOND CONDITION
        
        counter_third = 0 # THIRD CONDITION
        p_third = []      # THIRD CONDITION
            
            
        counter_first+=1
        p_first.append(current_battery)
        if counter_first == 1: #3
            
            #ENVOI MAIL BATTERIE FAIBLE
            
            subject = "Batterie faible"

            msg = "Le niveau de batterie mesure est actuellement de" + str(current_battery) + "V", "la niveau de batterie est donc faible."

            message = 'Subject: {}\n\n{}'.format(subject, msg)

            #reciever = 'blabla@gmail.com'

            server.sendmail("blabla@gmail.com", reciever, message)
            
            counter_first = 0
            p_first = []
            
    # SECOND CONDITION    
    elif current_battery < 3.7 and current_battery > 0:
        
        counter_first = 0 # FIRST CONDITION
        p_first = []      # FIRST CONDITION
        
        counter_third = 0 # THIRD CONDITION
        p_third = []      # THIRD CONDITION
        
        counter_second+=1
        p_second.append(current_battery)
        if counter_second == 1: #3
            
            #ENVOI DE MAIL BATTERIE PLATE
            
            subject = "Batterie plate"

            msg = "Le niveau de batterie mesure est actuellement de" + str(current_battery) + "V", "la batterie est donc plate."

            message = 'Subject: {}\n\n{}'.format(subject, msg)

            #reciever = 'blabla@gmail.com'

            server.sendmail("blabla@gmail.com", reciever, message)
            
            
            counter_second = 0
            p_second = []

        
    # THIRD CONDITION    
    elif current_battery<0 or current_battery > 4.3 :
        
        counter_first = 0 # FIRST CONDITION
        p_first = []      # FIRST CONDITION
        
        counter_second = 0 # SECOND CONDITION
        p_second = []      # SECOND CONDITION
        
        counter_third+=1
        p_third.append(current_battery)
        if counter_third == 1: #3
            
            #ENVOI MAIL WTF LA BATTERIE
            
            subject = "Donnees aberrantes"

            msg = "Le niveau de batterie mesure est actuellement de" + str(current_battery) + "V", "veuillez verifier l'etat de la batterie."

            message = 'Subject: {}\n\n{}'.format(subject, msg)

            #reciever = 'blabla@gmail.com'

            server.sendmail("blabla@gmail.com", reciever, message)
            
            counter_third = 0
            p_third = []
        
    # OTHER ALERTS
    o_first.append(current_time)
    if o_first[0] == o_first[1] and o_first[1] == o_first[2]:
        
        #ENVOI MAIL MANQUE DE DONNEES
        
        subject = "Aucunes donnees envoyees"

        msg = "Aucune donnee n'a ete recue depuis 15min"

        message = 'Subject: {}\n\n{}'.format(subject, msg)

        #reciever = 'blabla@gmail.com'

        server.sendmail("blabla@gmail.com", reciever, message)
        
        o_first = [1,2]
    else:
        o_first.pop(0)
        
        
        
        
        
    time.sleep(300) #delay of 300 seconds


















