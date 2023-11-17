#pragma once
#include "Client.h"

class BankService {
	friend class Client;

protected: // ������������� ������������ protected
	int years;
	double percent; // � ������� 1.XX..
	double body;

	BankService() {
		this->years = -1;
		this->percent = -1;
		this->body = -1;
	}
	BankService(int years) {
		this->years = years;
		this->percent = -1;
		this->body = -1;
	}
	BankService(double body) {
		this->body = body;
		this->years = -1;
		this->percent = -1;
	}
	BankService(int years, double percent, double body) {
		this->years = years;
		this->percent = percent;
		this->body = body;
	}

	void setYear(int newYear) {
		this->years = newYear;
	}
	void setBody(double newBody) {
		this->body = newBody;
	}
	void setPercent(double newPercent) {
		this->percent = newPercent;
	}

public:
	int getYears() {
		return this->years;
	}
	double getPercent() {
		return this->percent;
	}
	double getBody() {
		return this->body;
	}

	double getInterestAmount() {
		double interestAmount = 0;
		for (int i = 0; i < this->getYears(); i++)
			interestAmount += this->getBody() * (this->getPercent() - 1);
		return interestAmount;
	}
};
