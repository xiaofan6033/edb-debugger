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

#include "BinarySearcher.h"
#include "edb.h"
#include "DialogASCIIString.h"
#include "DialogBinaryString.h"
#include <QMenu>

namespace BinarySearcherPlugin {

//------------------------------------------------------------------------------
// Name: BinarySearcher
// Desc:
//------------------------------------------------------------------------------
BinarySearcher::BinarySearcher() : menu_(0) {
}

//------------------------------------------------------------------------------
// Name: ~BinarySearcher
// Desc:
//------------------------------------------------------------------------------
BinarySearcher::~BinarySearcher() {
}

//------------------------------------------------------------------------------
// Name: menu
// Desc:
//------------------------------------------------------------------------------
QMenu *BinarySearcher::menu(QWidget *parent) {

	Q_ASSERT(parent);

	if(!menu_) {
		menu_ = new QMenu(tr("BinarySearcher"), parent);
		menu_->addAction(tr("&Binary String Search"), this, SLOT(show_menu()), QKeySequence(tr("Ctrl+F")));
	}

	return menu_;
}

//------------------------------------------------------------------------------
// Name: stack_context_menu
// Desc:
//------------------------------------------------------------------------------
QList<QAction *> BinarySearcher::stack_context_menu() {

	QList<QAction *> ret;

	auto action_find = new QAction(tr("&Find ASCII String"), this);
	connect(action_find, SIGNAL(triggered()), this, SLOT(mnuStackFindASCII()));
	ret << action_find;

	return ret;
}

//------------------------------------------------------------------------------
// Name: show_menu
// Desc:
//------------------------------------------------------------------------------
void BinarySearcher::show_menu() {
	static auto dialog = new DialogBinaryString(edb::v1::debugger_ui);
	dialog->show();
}

//------------------------------------------------------------------------------
// Name: mnuStackFindASCII
// Desc:
//------------------------------------------------------------------------------
void BinarySearcher::mnuStackFindASCII() {
	static auto dialog = new DialogASCIIString(edb::v1::debugger_ui);
	dialog->show();
}

#if QT_VERSION < 0x050000
Q_EXPORT_PLUGIN2(BinarySearcher, BinarySearcher)
#endif

}
