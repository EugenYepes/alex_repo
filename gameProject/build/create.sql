PRAGMA foreign_keys = ON;

CREATE TABLE IF NOT EXISTS accounts(
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	email TEXT NOT NULL UNIQUE,
	username TEXT NOT NULL UNIQUE,
	account_type TEXT NOT NULL CHECK (account_type IN ('player', 'reviewer')),
	pref_platform TEXT,
	outlet_name TEXT
);

CREATE TABLE IF NOT EXISTS games(
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	title TEXT NOT NULL UNIQUE,
	release_year INTEGER NOT NULL,
	genre TEXT NOT NULL,
	status TEXT NOT NULL CHECK (status in ('backlog', 'inprogress', 'completed')),
	medium_type TEXT NOT NULL CHECK (medium_type in ('digital', 'hardcopy')),
	file_size_gb INTEGER NOT NULL,
	drm_platform TEXT NOT NULL,
	has_box INTEGER NOT NULL CHECK (has_box in (0, 1)),
	region TEXT
);

CREATE TABLE IF NOT EXISTS backlog_assignments(
	account_id INTEGER NOT NULL,
	game_id INTEGER NOT NULL,
	assigned_date TEXT NOT NULL DEFAULT(DATE('now')),
	PRIMARY KEY ( account_id , game_id ),
	FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE,
	FOREIGN KEY (game_id) REFERENCES games(id) ON DELETE CASCADE
);

CREATE TABLE IF NOT EXISTS reviews(
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	game_id INTEGER NOT NULL,
	account_id INTEGER NOT NULL,
	score INTEGER NOT NULL CHECK (score BETWEEN 0 AND 100),
	summary_text TEXT NOT NULL,
	review_date TEXT NOT NULL DEFAULT(DATE('now')),
	FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE,
	FOREIGN KEY (game_id) REFERENCES games(id) ON DELETE CASCADE
);

SELECT score FROM reviews
	LEFT JOIN games ON reviews.game_id = games.id;