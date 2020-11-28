/*
 * Hydrogen
 * Copyright(c) 2002-2008 by Alex >Comix< Cominu [comix@users.sourceforge.net]
 *
 * http://www.hydrogen-music.org
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY, without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

#ifndef LCDCOMBO_H
#define LCDCOMBO_H


#include <QtGui>
#include <QtWidgets>

#include <core/Object.h>

class Button;
class LCDDisplay;

class LCDCombo : public QWidget, public H2Core::Object
{
		H2_OBJECT
		Q_OBJECT
	public:
		explicit LCDCombo( QWidget *pParent, int digits = 5 );
		~LCDCombo();

		bool addItem( const QString &text );
		void addSeparator();
		int selected();
		void deactivate();
		void deactivate(QString text );
		bool select(int idx );
		bool select(int idx, bool emitValueChanged );


	private slots:
		void changeText( QAction* );
		void onClick( Button* );

	signals:
		void valueChanged( int idx );

	private:
		QList<QAction*> actions;
		LCDDisplay *display;
		Button *button;
		QMenu *pop;
		int size;
		int active;
		static const QString SEPARATOR;

		virtual void mousePressEvent( QMouseEvent *ev );
		virtual void wheelEvent( QWheelEvent * ev );
};


#endif
