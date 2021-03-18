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
client.switch_database('db_username')

import smtplib
server = smtplib.SMTP_SSL("smtp.gmail.com",465)

#server.login("blabla@gmail.com","email_password") # its now done below after itteration = 0

#EMAIL EXAMPLE**********************************

#subject = str(prenom) + " " + str(age) + ' ans en etat a surveiller'

#msg = "Le taux de SpO2 de " + str(prenom) + " " + str(age) + " ans est de " + str(taux[i]) + ", sa temperature s'aggrave et est de" + str(t) + "C et "+ str(prenom) +" vient de tousser."

#message = 'Subject: {}\n\n{}'.format(subject, msg)




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

#ACCELERATION**************************************
# a lists are for acceleration
# a_count are for accelerations too

a_first = [] # FIRST CONDITION
a_count_first = 0  # FIRST CONDITION

a_second = [] # SECOND CONDITION
a_count_second = 0  # SECOND CONDITION

a_third = [] # THIRD CONDITION
a_count_third = 0  # THIRD CONDITION



#OXYMETER******************************************
#SPO2
# s lists are for acceleration
# s_count are for accelerations too

s_first = [] # FIRST CONDITION
s_count_first = 0  # FIRST CONDITION

s_second = [] # SECOND CONDITION
s_count_second = 0  # SECOND CONDITION

s_third = [] # THIRD CONDITION
s_count_third = 0  # THIRD CONDITION

s_fourth = [] # FOURTH CONDITION
s_count_fourth = 0  # FOURTH CONDITION

#OTHER*********************************************
# o lists are for other alerts
# AUCUNE DONNEES
o_first = [1,2]

# Number of iterations in the loop
itteration = 0

# reciever is now from influx

while loop:
    
    if itteration == 0:
        server = smtplib.SMTP_SSL("smtp.gmail.com",465)
        server.login("blabla@gmail.com","email_password")
    
    itteration +=1
    
    
    #Temperature data
    query='SELECT last(Temperature) as lastdata FROM "Test"' 
    rs = client.query(query)
    temperature_values = list(rs.get_points(measurement='Test')) # *********************MODIFIABLE*********************
    
    #Battery data
    query='SELECT last(Niveau_de_batterie) as lastdata FROM "Test"'
    rs = client.query(query)
    battery_values = list(rs.get_points(measurement='Test')) # *********************MODIFIABLE*********************
    
    #Acceleration data
    # Xout
    #query = 'SELECT last(Xout) as lastdata FROM "Test"'
    #rs = client.query(query)
    #xout_values = list(rs.get_points(measurement='Test')) # *********************MODIFIABLE*********************
    # Yout
    #query = 'SELECT last(Yout) as lastdata FROM "Test"'
    #rs = client.query(query)
    #yout_values = list(rs.get_points(measurement='Test')) # *********************MODIFIABLE*********************
    # Zout
    #query = 'SELECT last(Zout) as lastdata FROM "Test"'
    #rs = client.query(query)
    #zout_values = list(rs.get_points(measurement='Test')) # *********************MODIFIABLE*********************
    # Norm
    query = 'SELECT last(Norm) as lastdata FROM "Test"'
    rs = client.query(query)
    norm_values = list(rs.get_points(measurement='Test')) # *********************MODIFIABLE*********************
    
    #Oxymeter data
    #SPO2
    query = 'SELECT last(SpO2) as lastdata FROM "Test"'
    rs = client.query(query)
    spo2_values = list(rs.get_points(measurement='Test')) # *********************MODIFIABLE*********************
    
    #Patient data
    # MAIL
    #query = 'SELECT last(Adresse_mail) as lastdata FROM "Test"'
    #rs = client.query(query)
    #mail_adress_values = list(rs.get_points(measurement='Test')) # *********************MODIFIABLE*********************
    # Age
    #query = 'SELECT last(Âge) as lastdata FROM "Experience 2"'
    #rs = client.query(query)
    #age_values = list(rs.get_points(measurement='Experience 2')) # *********************MODIFIABLE*********************
    # PatientID
    #query = 'SELECT last(PatientID) as lastdata FROM "Test"'
    #rs = client.query(query)
    #patientid_values = list(rs.get_points(measurement='Test')) # *********************MODIFIABLE*********************
    # Antécédent médical
    #query = 'SELECT last(BPCO) as lastdata FROM "Experience 2"'
    #rs = client.query(query)
    #antec_medic_values = list(rs.get_points(measurement='Experience 2')) # *********************MODIFIABLE*********************
    
    
    #reciever = '@gmail.com'
    #current_bpco = '2'
    #current_patientid = ''
    
    
    
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
    
    #Beginning anylising accelerations
    # Xout
    #for i in xout_values:
    #    current_xout = i.get('lastdata')
    #    #current time is the same
    # Yout
    #for i in yout_values:
    #    current_yout = i.get('lastdata')
    #    #current time is the same
    # Zout
    #for i in zout_values:
    #    current_zout = i.get('lastdata')
    #    #current time is the same
    # Norm
    for i in norm_values:
        current_norm = i.get('lastdata')
        #current time is the same
    
    #Beginning anylising accelerations
    # SPO2
    for i in spo2_values:
        current_spo2 = i.get('lastdata')
        #current time is the same
    
    
    
    #Beginning anylising patient data
    # Mail
    #for i in mail_adress_values:
    #    if i.get('lastdata') != "default":
    #        reciever = i.get('lastdata')
    # Age
    #for i in age_values:
    #    if i.get('lastdata') != "default":
    #        current_age = i.get('lastdata')
    # PatientID
    #for i in patientid_values:
    #    if i.get('lastdata') != "default":
    #        current_patientid = i.get('lastdata')
    # BPCO
    #for i in antec_medic_values:
    #    if i.get('lastdata') != "default":
    #        current_bpco = i.get('lastdata')
    
    
    
    
    # VERIFY THAT WE HAVE A DIFFERENT VALUE FROM LAST ONE
    
    o_first.append(current_time)
    if o_first[0] == o_first[1] and o_first[1] == o_first[2]:
        
        #ENVOI MAIL MANQUE DE DONNEES
        
        
        subject = "Aucunes donnees envoyees"

        msg = "Aucune donnee n'a ete recue depuis 15min"

        message = 'Subject: {}\n\n{}'.format(subject, msg)

        reciever = 'medecin@gmail.com'

        server.sendmail("blabla@gmail.com", reciever, message)
        
        reciever = 'patient@gmail.com'

        server.sendmail("blabla@gmail.com", reciever, message)
        
        #server.quit()
        
        o_first = [1,2]
        
    else: # That means we have a different value so we can treat it
        o_first.pop(0)
    
    
        # FIRST CONDITION
        if current_temperature > 38 and current_temperature < 38.3: # Adapatation selon simu n'importe quel âge

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

            if count_first ==4 : # si 4 valeurs d'affilé

                #ENVOI DE MAIL  APPARITION DE FIEVRE


                subject = "Appartition d'une fievre"

                msg = "La temperature de "+current_patientid+ " est actuellement de " + str(current_temperature) + "C", "c'est le debut d'une fievre."

                message = 'Subject: {}\n\n{}'.format(subject, msg)

                reciever = 'medecin@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                #server.quit()

                m_first=[]
                count_first = 0



        # SECOND CONDITION
        elif current_temperature >= 38.3 and current_temperature < 43: # Adapatation selon simu   n'importe qui
    
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
            if count_second == 4: # si 4 valeurs d'affilé


                #ENVOI DE MAIL AGGRAVATION FIEVRE


                subject = "Aggravation de la fievre"

                msg = "La temperature de "+current_patientid+ " est actuellement de " + str(current_temperature) + "C", "la fievre s'est aggravee."

                message = 'Subject: {}\n\n{}'.format(subject, msg)

                reciever = 'medecin@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                #server.quit()

                m_second = []
                count_second = 0

        # THIRD CONDITION
        elif current_temperature > 30 and current_temperature < 36:


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
            if count_second == 3: # si 3 valeurs d'affilé

                #ENVOI DE MAIL Donnée anormal

                subject = "Donnee anormale"

                msg = "La temperature de "+current_patientid+ " est actuellement de " + str(current_temperature) + "C", "ces donnees sont anormales. Veuillez contacter votre medecin."

                message = 'Subject: {}\n\n{}'.format(subject, msg)

                reciever = 'medecin@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                reciever = 'patient@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                #server.quit()

                count_third = 0
                m_third = []

        # FOURTH CONDITION
        elif current_temperature > 15 and current_temperature <= 30:

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
            if count_fourth ==4: #si 4 valeurs d'affilé

                #ENVOI DE MAIL DISPOSITIF RETIRE


                subject = 'Dispositif retire'

                msg = 'La temperature mesuree est actuellement de ' + str(current_temperature) + 'C, ' + 'le dispositif a ete retire.'

                message = 'Subject: {}\n\n{}'.format(subject, msg)

                reciever = 'medecin@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                reciever = 'patient@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                #server.quit()

                count_fourth = 0
                m_fourth = []

        # FIFTH CONDITION
        elif current_temperature >=43 or current_temperature<=15:
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
            if count_fifth ==3: #si 3 valeurs

                #ENVOI DE MAIL DONNEES ABERRANTES


                subject = "Donnees aberrantes"

                msg = "La temperature mesuree est actuellement de " + str(current_temperature) + "C", "veuillez verifier la position du capteur de temperature."

                message = 'Subject: {}\n\n{}'.format(subject, msg)

                reciever = 'medecin@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                reciever = 'patient@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                #server.quit()

                count_fifth = 0
                m_fifth = []

        # LAST CONDITION REGARDING TEMPERATURE
        
        else: # if temperature [36-38] then its ok temperature

            count_first = 0 # FIRST CONDITION
            m_first = []    # FIRST CONDITION

            count_second = 0 # SECOND CONDITION
            m_second = []    # SECOND CONDITION

            count_third = 0 # THIRD CONDITION
            m_third = []    # THIRD CONDITION

            count_fourth = 0 # FOURTH CONDITION
            m_fourth = []    # FOURTH CONDITION

            m_fifth = []    # FIFTH CONDITION
            count_fifth = 0 # FIFTH CONDITION


        #BATTERY

        # FIRST CONDITION
        if current_battery < 3.9 and current_battery >3.7:
        #if current_battery < 4.2:

            counter_second = 0 # SECOND CONDITION
            p_second = []      # SECOND CONDITION

            counter_third = 0 # THIRD CONDITION
            p_third = []      # THIRD CONDITION


            counter_first+=1
            p_first.append(current_battery)
            if counter_first == 3: #3

                #ENVOI MAIL BATTERIE FAIBLE


                subject = "Batterie faible"

                msg = "Le niveau de batterie mesure est actuellement de" + str(current_battery) + "V", "le niveau de batterie est donc faible."

                message = 'Subject: {}\n\n{}'.format(subject, msg)

                reciever = 'medecin@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                reciever = 'patient@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                #server.quit()

                counter_first = 0
                p_first = []

        # SECOND CONDITION    
        elif current_battery <= 3.7 and current_battery > 0:

            counter_first = 0 # FIRST CONDITION
            p_first = []      # FIRST CONDITION

            counter_third = 0 # THIRD CONDITION
            p_third = []      # THIRD CONDITION

            counter_second+=1
            p_second.append(current_battery)
            if counter_second == 3: #3

                #ENVOI DE MAIL BATTERIE PLATE


                subject = "Batterie plate"

                msg = "Le niveau de batterie mesure est actuellement de " + str(current_battery) + "V", "la batterie est donc plate."

                message = 'Subject: {}\n\n{}'.format(subject, msg)

                reciever = 'medecin@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                reciever = 'patient@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                #server.quit()


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
            if counter_third == 3: #3

                #ENVOI MAIL WTF LA BATTERIE


                subject = "Donnees aberrantes"

                msg = "Le niveau de batterie mesure est actuellement de " + str(current_battery) + "V", "veuillez verifier l'etat de la batterie."

                message = 'Subject: {}\n\n{}'.format(subject, msg)

                reciever = 'medecin@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                reciever = 'patient@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                #server.quit()

                counter_third = 0
                p_third = []
            
        else: # if battery is ok, that means battery in interval [3.9-4.3]
            
            p_first = [] # FIRST CONDITION
            counter_first = 0 # FIRST CONDITION

            p_second = [] # SECOND CONDITION
            counter_second = 0 # SECOND CONDITION

            p_third = [] # THIRD CONDITION
            counter_third = 0 # THIRD CONDITION
          
        # BPCO + SPO2
        
        if current_bpco == "1":
            
            # FIRST CONDITION
            if current_spo2 < 88 and current_spo2>70:
                
                s_second = [] # SECOND CONDITION
                s_count_second = 0  # SECOND CONDITION

                s_third = [] # THIRD CONDITION
                s_count_third = 0  # THIRD CONDITION

                s_fourth = [] # FOURTH CONDITION
                s_count_fourth = 0  # FOURTH CONDITION
                
                
                s_count_first +=1
                s_first.append(current_spo2)
                if s_count_first == 1: # count
                    
                    #ENVOI DE MAIL TAUX FAIBLE


                    subject = "Taux de SpO2 faible"

                    msg = "Le niveau de SpO2 mesure est de " + str(current_spo2) + "%", "c'est tres faible, veuillez contacter votre medecin."

                    message = 'Subject: {}\n\n{}'.format(subject, msg)
                    
                    reciever = 'medecin@gmail.com'

                    server.sendmail("blabla@gmail.com", reciever, message)


                    s_count_first = 0
                    s_first = []
                    
            # SECOND CONDITION
            elif current_spo2 <=70 and current_spo2 >60:
                
                s_first = [] # FIRST CONDITION
                s_count_first = 0  # FIRST CONDITION
                
                s_third = [] # THIRD CONDITION
                s_count_third = 0  # THIRD CONDITION

                s_fourth = [] # FOURTH CONDITION
                s_count_fourth = 0  # FOURTH CONDITION
                
                s_count_second +=1
                s_second.append(current_spo2)
                
                if s_count_second == 1:
                    
                    #ENVOI DE MAIL TAUX CRITIQUE


                    subject = "Taux de SpO2 critique"

                    msg = "Le niveau de SpO2 mesure est de " + str(current_spo2) + "%", "c'est un taux critique ! Veuillez contacter votre medecin."

                    message = 'Subject: {}\n\n{}'.format(subject, msg)
                    
                    reciever = 'medecin@gmail.com'

                    server.sendmail("blabla@gmail.com", reciever, message)
            
                    s_count_second = 0
                    s_second = []
            
            
            # THIRD CONDITION
            elif current_spo2 <=60 and current_spo2 >0:
                
                s_first = [] # FIRST CONDITION
                s_count_first = 0  # FIRST CONDITION
                
                s_second = [] # SECOND CONDITION
                s_count_second = 0  # SECOND CONDITION

                s_fourth = [] # FOURTH CONDITION
                s_count_fourth = 0  # FOURTH CONDITION
                
                s_count_third +=1
                s_third.append(current_spo2)
                
                if s_count_third == 1:
                    
                    #ENVOI DE MAIL TAUX ABBERRANT


                    subject = "Donnees de SpO2 aberrantes"

                    msg = "Le niveau de SpO2 mesure est de " + str(current_spo2) + "%", "c'est un resultat aberrant, veuillez verifier l'etat de l'oxymetre."

                    message = 'Subject: {}\n\n{}'.format(subject, msg)
                    
                    reciever = 'medecin@gmail.com'

                    server.sendmail("blabla@gmail.com", reciever, message)

                    reciever = 'patient@gmail.com'

                    server.sendmail("blabla@gmail.com", reciever, message)
            
                    s_count_third = 0
                    s_third = []
                    
            
            # FOURTH CONDITION
            else: # it means good spo2 level
                
                s_first = [] # FIRST CONDITION
                s_count_first = 0  # FIRST CONDITION
                
                s_second = [] # SECOND CONDITION
                s_count_second = 0  # SECOND CONDITION

                s_third = [] # THIRD CONDITION
                s_count_third = 0  # THIRD CONDITION
                
        #*****************************************
            
        if current_bpco == "2":
            
            
            # FIRST CONDITION
            if current_spo2 < 93 and current_spo2>75:
                
                s_second = [] # SECOND CONDITION
                s_count_second = 0  # SECOND CONDITION

                s_third = [] # THIRD CONDITION
                s_count_third = 0  # THIRD CONDITION

                s_fourth = [] # FOURTH CONDITION
                s_count_fourth = 0  # FOURTH CONDITION
                
                
                s_count_first +=1
                s_first.append(current_spo2)
                if s_count_first == 1: # count
                    
                    #ENVOI DE MAIL TAUX FAIBLE


                    subject = "Taux de SpO2 faible"

                    msg = "Le niveau de SpO2 mesure est de " + str(current_spo2) + "%", "c'est tres faible. Veuillez contacter votre medecin."

                    message = 'Subject: {}\n\n{}'.format(subject, msg)
                    
                    reciever = 'medecin@gmail.com'

                    server.sendmail("blabla@gmail.com", reciever, message)


                    s_count_first = 0
                    s_first = []
                    
            # SECOND CONDITION
            elif current_spo2 <=75 and current_spo2 >65:
                
                s_first = [] # FIRST CONDITION
                s_count_first = 0  # FIRST CONDITION
                
                s_third = [] # THIRD CONDITION
                s_count_third = 0  # THIRD CONDITION

                s_fourth = [] # FOURTH CONDITION
                s_count_fourth = 0  # FOURTH CONDITION
                
                s_count_second +=1
                s_second.append(current_spo2)
                
                if s_count_second == 1:
                    
                    #ENVOI DE MAIL TAUX CRITIQUE


                    subject = "Taux de SpO2 critique"

                    msg = "Le niveau de SpO2 mesure est de " + str(current_spo2) + "%", "c'est un taux critique ! Veuillez contacter votre medecin."

                    message = 'Subject: {}\n\n{}'.format(subject, msg)
                    
                    reciever = 'medecin@gmail.com'

                    server.sendmail("blabla@gmail.com", reciever, message)
            
                    s_count_second = 0
                    s_second = []
            
            
            # THIRD CONDITION
            elif current_spo2 <=65 and current_spo2 >0:
                
                s_first = [] # FIRST CONDITION
                s_count_first = 0  # FIRST CONDITION
                
                s_second = [] # SECOND CONDITION
                s_count_second = 0  # SECOND CONDITION

                s_fourth = [] # FOURTH CONDITION
                s_count_fourth = 0  # FOURTH CONDITION
                
                s_count_third +=1
                s_third.append(current_spo2)
                
                if s_count_third == 1:
                    
                    #ENVOI DE MAIL TAUX ABERRANT


                    subject = "Donnees de SpO2 aberrantes"

                    msg = "Le niveau de SpO2 mesure est de " + str(current_spo2) + "%", "c'est un resultat aberrant, veuillez verifier l'etat de l'oxymetre."

                    message = 'Subject: {}\n\n{}'.format(subject, msg)

                    reciever = 'medecin@gmail.com'

                    server.sendmail("blabla@gmail.com", reciever, message)

                    reciever = 'patient@gmail.com'

                    server.sendmail("blabla@gmail.com", reciever, message)
            
                    s_count_third = 0
                    s_third = []
                    
            
            # FOURTH CONDITION
            else: # it means good spo2 level
                
                s_first = [] # FIRST CONDITION
                s_count_first = 0  # FIRST CONDITION
                
                s_second = [] # SECOND CONDITION
                s_count_second = 0  # SECOND CONDITION

                s_third = [] # THIRD CONDITION
                s_count_third = 0  # THIRD CONDITION
                
                
                
            
        # ACCELERATION    
        
        # FIRST CONDITION
        if current_norm >= 2 and current_norm < 2.2: # Adapatation selon simu n'importe quel âge

            a_second = [] # SECOND CONDITION
            a_count_second = 0  # SECOND CONDITION

            a_third = [] # THIRD CONDITION
            a_count_third = 0  # THIRD CONDITION
            

            a_count_first +=1 # FIRST CONDITION
            a_first.append(current_norm)

            if a_count_first ==1 : # si 4 valeurs d'affilé

                #ENVOI DE MAIL APPARITION DE TOUX


                subject = "Appartition d'une toux seche"

                msg = "La valeur de la norme de l'acceleration de la toux de "+current_patientid+ " est actuellement de " + str(current_norm) + "m/s2", "c'est le debut d'une toux seche."

                message = 'Subject: {}\n\n{}'.format(subject, msg)
                
                reciever = 'medecin@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)


                a_first=[]
                a_count_first = 0
        
        # SECOND CONDITION
        elif current_norm >= 2.2 and current_norm < 2.5: # Adapatation selon simu n'importe quel âge

            a_first=[] # FIRST CONDITION
            a_count_first = 0 # FIRST CONDITION

            a_third = [] # THIRD CONDITION
            a_count_third = 0  # THIRD CONDITION
            

            a_count_second +=1 # SECOND CONDITION
            a_second.append(current_norm)

            if a_count_second ==1 : # si 4 valeurs d'affilé

                #ENVOI DE MAIL AGGRAVATION DE TOUX


                subject = "Aggravation de la toux seche"

                msg = "La valeur de la norme de l'acceleration de la toux de "+current_patientid+ " est actuellement de " + str(current_norm) + "m/s2", "la toux seche s'est aggravee."

                message = 'Subject: {}\n\n{}'.format(subject, msg)
                
                reciever = 'medecin@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)


                a_second=[]
                a_count_second = 0
            
        # THIRD CONDITION
        elif current_norm >= 2.5: # Adapatation selon simu n'importe quel âge

            a_first=[] # FIRST CONDITION
            a_count_first = 0 # FIRST CONDITION

            a_second = [] # SECOND CONDITION
            a_count_second = 0  # SECOND CONDITION
            

            a_count_third +=1 # THIRD CONDITION
            a_third.append(current_norm)

            if a_count_third ==1 : # si 4 valeurs d'affilé

                #ENVOI DE MAIL DONNEES ABERRANTES

                subject = "Donnees aberrantes"

                msg = "La valeur de la norme de l'acceleration de la toux de "+current_patientid+ " est actuellement de " + str(current_norm) + "m/s2", "veuillez verifier l'accelerometre."

                message = 'Subject: {}\n\n{}'.format(subject, msg)

                reciever = 'medecin@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)

                reciever = 'patient@gmail.com'

                server.sendmail("blabla@gmail.com", reciever, message)


                a_third=[]
                a_count_third = 0
                
        # FOURTH CONDITION
        else: # means acceleration in interval [0-2[
            
            a_first=[] # FIRST CONDITION
            a_count_first = 0 # FIRST CONDITION

            a_second = [] # SECOND CONDITION
            a_count_second = 0  # SECOND CONDITION

            a_third = [] # THIRD CONDITION
            a_count_third = 0  # THIRD CONDITION
            
       
    time.sleep(300) #delay of 300 seconds
    
    if itteration == 10: # reset smtp timeout 
        server.quit()
        itteration = 0
    
    
    















