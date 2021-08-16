inline void readSent() {
	char sentChar[MAXLEN];
	std::ifstream sentFile;

	sentFile.open("stmt\\lang_" + lang + ".txt");
	while (1) {
		if (sentFile.peek() == EOF) {
			tempFile << "[System] Loading Sent. completed.\n";
			break;
		}

		sentFile.getline(sentChar, 1024);
		ll sentCharSize = strlen(sentChar);
		char colonLeft[MAXLEN] = {'\0'}, colonRight[MAXLEN] = {'\0'};
		ll colonLeftSize = 0, colonRightSize = 0;
		bool firstCheck = true;
		for (re ll i = 0; i < sentCharSize; ++i) {
			if (sentChar[i] != ':' || !firstCheck) {
				if (firstCheck) {
					colonLeft[colonLeftSize++] = sentChar[i];
				} else {
					colonRight[colonRightSize++] = sentChar[i];
				}
			}
			if (sentChar[i] == ':' && firstCheck) {
				firstCheck = false;
			}
		}
		sent[colonLeft] = colonRight;
	}
	sentFile.close();
}
inline bool readSave() {
	std::ifstream preloadFile;
	preloadFile.open("save\\__preload.txt");
	preloadFile.getline(saveFileName, 1024);
	preloadFile.close();
	bool successLoad = load(saveFileName);
	if (!successLoad) {
		tempFile << "[System] Load failed, create save file." << std::endl;
		save(saveFileName);
		initFunc();
		preinit();
	}
	pushReminderStack(-1, RGB(60, 120, 150));
	return successLoad;
}
