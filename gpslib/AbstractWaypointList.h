// $Id$
// Copyright (c) 2008 Oliver Lau <oliver@ersatzworld.net>
// Alle Rechte vorbehalten.


#ifndef __ABSTRACTWAYPOINTLIST_H_
#define __ABSTRACTWAYPOINTLIST_H_

#include <vector>
#include <string>

#include "Value.h"
#include "Polygon.h"

namespace GPS {

    template<class T>
    class AbstractWaypointList {
    protected:
        std::string _Name;
        std::string _Comment;
        std::string _Description;
        std::string _Source;
        std::string _Link;
        std::string _Type;
        IntValue _Number;

        /// Chronologisch sortierte Liste der Trackpunkte.
        std::vector<T*> samples;

    public:
        AbstractWaypointList(void) { /* ... */ };

        virtual ~AbstractWaypointList(void) { /* ... */ };

        /// L�nge in Metern zur�ckgeben.
        /// @return Entfernung in Metern
        virtual double distance(void) const = 0;

        /// Ermitteln, ob die Liste Punkte enth�lt.
        /// @return true, wenn die Liste leer ist.
        inline bool isEmpty(void) const
        {
            return samples.size() == 0;
        }

        /// Letzten Punkt aus der Liste entfernen.
        inline void pop(void)
        {
            if (!isEmpty())
                samples.pop_back();
        }

        /// Routen-Daten l�schen.
        inline void clear(void)
        {
            samples.clear();
        }

        /// Einen Punkt an die Liste anh�ngen.
        /// @param pt Anzuh�ngender Punkt. NULL-Zeiger werden ignoriert.
        inline void append(T* pt)
        {
            if (pt != NULL)
                samples.push_back(pt);
        }

        /// Punkt-Liste zur�ckgeben.
        /// @return Punkt-Liste
        /// @see samples
        inline std::vector<T*>& points(void)
        {
            return samples;
        }


        /// Durch den Punkte eingeschlossene Fl�che in Quadratmetern zur�ckgeben.
        /// @return Fl�che in Quadratmetern
        double area(void) const
        {
            GPS::Polygon p;
            for (typename std::vector<T*>::const_iterator i = samples.begin(); i != samples.end(); ++i)
                p << (*i)->toUTM();
            p.close();
            return p.area();
        }

        /// Namen zur�ckgeben.
        inline const std::string& name(void) const { return _Name; }

        /// Kommentar zur�ckgeben.
        inline const std::string& comment(void) const { return _Comment; }

        /// Beschreibung zur�ckgeben.
        inline const std::string& description(void) const { return _Description; }

        /// Quelle zur�ckgeben.
        inline const std::string& source(void) const { return _Source; }

        /// Link zur�ckgeben.
        inline const std::string& link(void) const { return _Link; }

        /// Typ zur�ckgeben.
        inline const std::string& type(void) const { return _Type; }

        /// Nummer zur�ckgeben.
        inline const IntValue& number(void) const { return _Number; }

        /// Namen setzen.
        inline void setName(std::string name) { _Name = name; }

        /// Kommentar setzen.
        inline void setComment(std::string comment) { _Comment = comment; }

        /// Beschreibung setzen.
        inline void setDescription(std::string description) { _Description = description; }

        /// Quelle setzen.
        inline void setSource(std::string source) { _Source = source; }

        /// Link setzen.
        inline void setLink(std::string link) { _Link = link; }

        /// Typ setzen.
        inline void setType(std::string type) { _Type = type; }

        /// Nummer setzen.
        inline void setNumber(int number) { _Number = number; }

    };

};

#endif // __ABSTRACTWAYPOINTLIST_H_
