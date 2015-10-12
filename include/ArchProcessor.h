/*
Copyright (C) 2006 - 2015 Evan Teran
                          evan.teran@gmail.com

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef ARCHPROCESSOR_20070312_H_
#define ARCHPROCESSOR_20070312_H_

#include "State.h"
#include "Types.h"
#include <QCoreApplication>
#include <QStringList>
#include <QObject>
#include <vector>

class QByteArray;
class QString;
class QTreeWidgetItem;
class RegisterListWidget;
class State;

class ArchProcessor : public QObject {
	Q_OBJECT
	Q_DISABLE_COPY(ArchProcessor)
public:
	ArchProcessor();
	virtual ~ArchProcessor() {}

public:
	QStringList update_instruction_info(edb::address_t address);
	Register value_from_item(const QTreeWidgetItem &item);
	void edit_item(const QTreeWidgetItem &item);
	bool can_step_over(const edb::Instruction &inst) const;
	bool is_filling(const edb::Instruction &inst) const;
	void reset();
	void setup_register_view(RegisterListWidget *category_list);
	void update_register_view(const QString &default_region_name, const State &state);

private:
	void update_register(QTreeWidgetItem *item, const Register &reg) const;
	void update_fpu_view(int& itemNumber, const State &state, const QPalette& palette) const;

private:
	QTreeWidgetItem * split_flags_;
	State             last_state_;
	bool              has_mmx_;
	bool              has_xmm_;
	bool              has_ymm_;
	std::vector<QTreeWidgetItem*> register_view_items_;
};

#endif

