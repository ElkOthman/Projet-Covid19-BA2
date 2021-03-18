# Project-Covid19-BA2

Ce git contient toutes les parties de codes utilisées par l'équipe afin de créer les dispositifs médicaux périodiques et continus du projet.

Certains codes permettent d'utiliser les capteurs (Oxymetre, ADXL327, Temperature). C++

Un code permet de mesurer le niveau de batterie (Niveau_de_batterie). C++

Un autre code permet d'envoyer des données à une base de donnée InfluxDb (Envoi_donnes). C++

"Flash_memory" permet d'écrire des valeurs dans la mémoire flash (EEPROM) de l'ESP32. C++

"Connect_wifi" nous connecte à un réseau WiFi. C++

"Wifi_patientID" est un code permettant de créer une interface avec laquelle il est possible de récupérer les données insérées par le patient. C++

"mode_veille" est utilisé pour mettre l'esp en veille (deepsleep). C++

"python influx query" permet de récupérer les données de la base de donnée InfluxDB. Py

"Ovulation" et "Simulation temperature" sont les codes utilisés pour la simulation. Py

Pour envoyer les alertes au médecin/patient, les codes "Send mail python", "Experience 3 monitoring" et "Final Monitoring python" ont été utilisés. Py



