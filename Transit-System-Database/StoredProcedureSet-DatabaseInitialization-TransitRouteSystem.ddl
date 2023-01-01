DROP TABLE IF EXISTS ASchedule;
DROP TABLE IF EXISTS Serves;
DROP TABLE IF EXISTS Reached_by;
DROP TABLE IF EXISTS Hosts_event;
DROP TABLE IF EXISTS Site;
DROP TABLE IF EXISTS Contains;
DROP TABLE IF EXISTS Served_by;
DROP TABLE IF EXISTS Stop;
DROP TABLE IF EXISTS Route;
DROP TABLE IF EXISTS Works_on;
DROP TABLE IF EXISTS driven_by;
DROP TABLE IF EXISTS Ship;
DROP TABLE IF EXISTS driving_infractions;
DROP TABLE IF EXISTS Service_personnel;
DROP TABLE IF EXISTS Pilot;
DROP TABLE IF EXISTS Student;
DROP TABLE IF EXISTS Passenger;
DROP TABLE IF EXISTS Has_Phone_Number;
DROP TABLE IF EXISTS Persons;


CREATE TABLE IF NOT EXISTS Persons(
    sin INT PRIMARY KEY,
    first_name VARCHAR(20) NOT NULL,
    last_name VARCHAR(20) NOT NULL,
    gender enum('male', 'female') NOT NULL,
    date_of_birth DATE NOT NULL,
    street_address VARCHAR(50) NOT NULL,
    city VARCHAR(20) NOT NULL,
    province VARCHAR(20) NOT NULL,
    postal_code VARCHAR(20) NOT NULL,
    occupation VARCHAR(20) NOT NULL
);

CREATE TABLE IF NOT EXISTS Has_Phone_Number (
	phone_number INT PRIMARY KEY,
	sin INT NOT NULL,
	type ENUM('Personal', 'Home', 'Work', 'Other') NOT NULL,
	CONSTRAINT PERSONSPHONE_FK FOREIGN KEY(sin) REFERENCES Persons(sin)
);

CREATE TABLE IF NOT EXISTS Passenger (
    sin INT PRIMARY KEY,
    type ENUM('child', 'senior', 'student') NOT NULL,
    age INT NOT NULL,
    fare FLOAT NOT NULL,
    CONSTRAINT PERSONSPSNGR_FK FOREIGN KEY(sin) REFERENCES Persons(sin)
);

CREATE TABLE IF NOT EXISTS Student (
    sin INT PRIMARY KEY,
    level_of_education ENUM('secondary', 'post-secondary') NOT NULL,
    institution VARCHAR(20) NOT NULL,
    CONSTRAINT PERSONSTDNT_FK FOREIGN KEY(sin) REFERENCES Passenger(sin)
);

CREATE TABLE IF NOT EXISTS Pilot (
    sin INT PRIMARY KEY,
    salary FLOAT NOT NULL,
    years_of_service INT NOT NULL,
    CONSTRAINT PERSONSPILOT_FK FOREIGN KEY(sin) REFERENCES Persons(sin)
);

CREATE TABLE IF NOT EXISTS Service_personnel (
    sin INT PRIMARY KEY,
    specialization VARCHAR(20) NOT NULL,
    level ENUM('technician', 'senior technician', 'supervisor', 'manager')  NOT NULL,
    years_of_service INT NOT NULL,
    salary FLOAT NOT NULL,
    CONSTRAINT PERSONSRVCPRSNL_FK FOREIGN KEY(sin) REFERENCES Persons(sin)
);

CREATE TABLE IF NOT EXISTS driving_infractions (
    sin INT,
    date_of_occurrence DATE NOT NULL,
    type__of_infraction VARCHAR(20) NOT NULL,
    demerit_points INT NOT NULL,
    financial_penalty FLOAT NOT NULL,
    CONSTRAINT PILOTINFRCTN_FK FOREIGN KEY(sin) REFERENCES Pilot(sin),
    PRIMARY KEY(sin, date_of_occurrence)
);

CREATE TABLE IF NOT EXISTS Ship (
    ship_id INT PRIMARY KEY,
    years_in_operation INT NOT NULL,
    num_seats INT NOT NULL,
    manufacturer VARCHAR(20) NOT NULL,
    advertising_revenue FLOAT NOT NULL,
    fuel_type VARCHAR(20) NOT NULL
);

CREATE TABLE IF NOT EXISTS driven_by (
    ship_id INT,
    pilot1_id INT,
    pilot2_id INT,
    PRIMARY KEY(ship_id, pilot1_id, pilot2_id),
    CONSTRAINT SHIPDRVN_FK FOREIGN KEY(ship_id) REFERENCES Ship(ship_id),
    CONSTRAINT PILOTDRVN_FK FOREIGN KEY(pilot1_id) REFERENCES Pilot(sin),
    CONSTRAINT PILOTDRVN_FK FOREIGN KEY(pilot2_id) REFERENCES Pilot(sin)
);

CREATE TABLE IF NOT EXISTS Works_on (
    emp_id INT,
    ship_id INT,
    date DATE,
    cost FLOAT NOT NULL,
    PRIMARY KEY(emp_id, ship_id, date),
    CONSTRAINT SRVCPRSNLWRK_FK FOREIGN KEY(emp_id) REFERENCES Service_personnel(sin),
    CONSTRAINT SHIPWRK_FK FOREIGN KEY(ship_id) REFERENCES Ship(ship_id)
);

CREATE TABLE IF NOT EXISTS Route (
    route_id INT PRIMARY KEY,
    name VARCHAR(20) NOT NULL
);

CREATE TABLE IF NOT EXISTS Stop (
    stop_id INT PRIMARY KEY,
    name VARCHAR(20) NOT NULL
);

CREATE TABLE IF NOT EXISTS Served_by (
    route_id INT,
    ship_id INT,
    PRIMARY KEY(route_id, ship_id),
    CONSTRAINT ROUTESRVD_FK FOREIGN KEY(route_id) REFERENCES Route(route_id),
    CONSTRAINT SHIPSRVD_FK FOREIGN KEY(ship_id) REFERENCES Ship(ship_id)
);

CREATE TABLE IF NOT EXISTS Contains (
    route_id INT,
    stop_id INT,
    PRIMARY KEY(route_id, stop_id),
    CONSTRAINT ROUTECNTN_FK FOREIGN KEY(route_id) REFERENCES Route(route_id),
    CONSTRAINT STOPCNTN_FK FOREIGN KEY(stop_id) REFERENCES Stop(stop_id)
);

CREATE TABLE IF NOT EXISTS Site (
    phone_number INT PRIMARY KEY,
    name VARCHAR(20) NOT NULL,
    address VARCHAR(50) NOT NULL,
    capacity INT NOT NULL,
    category VARCHAR(20) NOT NULL
);

CREATE TABLE IF NOT EXISTS Hosts_event (
	  site_id INT,
	  name VARCHAR(20),
	  date_and_time DATETIME NOT NULL,
	  expected_number_of_participants INT NOT NULL,
    CONSTRAINT SITEHOST_FK FOREIGN KEY(site_id) REFERENCES Site(phone_number),
    PRIMARY KEY(name, site_id)
);

CREATE TABLE IF NOT EXISTS Reached_by (
    route_id INT,
    site_id INT,
    PRIMARY KEY(route_id, site_id),
    CONSTRAINT SITEREACH_FK FOREIGN KEY(site_id) REFERENCES Site(phone_number),
    CONSTRAINT ROUTEREACH_FK FOREIGN KEY(route_id) REFERENCES Route(route_id)
);


CREATE TABLE IF NOT EXISTS Serves (
    stop_id INT,
    site_id INT,
    PRIMARY KEY(stop_id, site_id),
    CONSTRAINT SITESRV_FK FOREIGN KEY(site_id) REFERENCES Site(phone_number),
    CONSTRAINT STOPSRV_FK FOREIGN KEY(stop_id) REFERENCES Stop(stop_id)
);

CREATE TABLE IF NOT EXISTS ASchedule (
    stop_id INT,
    route_id INT,
    ship_id INT,
    arrival_time TIME,
    PRIMARY KEY(stop_id, route_id, ship_id, arrival_time),
    CONSTRAINT STOPSCHD_FK FOREIGN KEY(stop_id) REFERENCES Stop(stop_id),
    CONSTRAINT ROUTESCHD_FK FOREIGN KEY(route_id) REFERENCES Route(route_id),
    CONSTRAINT SHIPSCHD_FK FOREIGN KEY(ship_id) REFERENCES Ship(ship_id)
);
