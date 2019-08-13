package units;

import abilities.Ability;
import actions.Action;
import exceptions.InvalidInfectException;
import exceptions.InvalidTransformException;
import exceptions.UnitIsDead;
import interfaces.Observer;
import interfaces.Subject;
import states.State;

import java.util.ArrayList;
import java.util.List;

abstract public class Unit implements Subject {
    protected Ability ability;
    protected Action action;
    protected State state;
    protected List<Observer> observers = new ArrayList<>();

    public Unit (String name, int hp, int dmg, double magicResist, String title, String type ) {
        this.state = new State(name, hp, dmg, magicResist, title, type);
    }

    public void ensureIsAlive() throws UnitIsDead {
        try {
            this.state.ensureIsAlive();
        } catch (UnitIsDead e) {
            this.notifyObservers();
            e.printStackTrace();
        }
    }

    public int getDamage() {
        return this.state.getDamage();
    }

    public int getHitPoints() {
        return this.state.getHitPoints();
    }

    public int getHitPointsLimit() {
        return this.state.getHitPointsLimit();
    }

    public double getMagicResist() {
        return this.state.getMagicResist();
    }

    public String getName() {
        return this.state.getName();
    }

    public String getTitle() {
        return this.state.getTitle();
    }

    public String getType() {
        return this.state.getType();
    }

    public Action getAction() {
        return this.action;
    }

    public Ability getAbility() {
        return this.ability;
    }

    public void setAction(Action newAction) {
        this.action = newAction;
    }

    public void setAbility(Ability newAbility) {
        this.ability = newAbility;
    }

    public void setState(State newState) {
        this.state = newState;
    }

    public void setHitPointsLimit(int hp) {
        this.state.setHitPointsLimit(hp);
    }

    public void takeDamage(int damage) throws UnitIsDead {
        this.state.takeDamage(damage);
    }

    public void takeMagicDamage(int damage) throws UnitIsDead {
        this.state.takeMagicDamage(damage);
    }

    public void addHitPoints(int hp) throws UnitIsDead {
        this.state.addHitPoints(hp);
    }

    public void attack(Unit enemy) {
        this.action.attack(enemy);
    }

    public void counterAttack(Unit enemy) {
        this.action.counterAttack(enemy);
    }

    public void infect(Unit enemy) throws InvalidInfectException {
        try {
            this.ability.infect(enemy);
        } catch (InvalidInfectException e) {
            e.printStackTrace();
        }
    }

    public void transform() throws InvalidTransformException {
        try {
            this.ability.transform();
        } catch (InvalidTransformException e) {
            e.printStackTrace();
        }
    }

    public String toString() {
        return "Unit: " + this.state;
    }

    public void attach(Observer observer) {
        this.observers.add(observer);
    }

    public void detach(Observer observer) {
        this.observers.remove(observer);
    }

    public void notifyObservers() throws UnitIsDead {
        for (Observer obs:
             this.observers) {
            obs.update(this);
        }
    }
}
