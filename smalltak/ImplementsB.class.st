Class {
	#name : #ImplementsB,
	#superclass : #Object,
	#category : #covarianza
}

{ #category : #'interface_b' }
ImplementsB >> methodA [
	Transcript show: 'methodA desde ImplementsB'
]

{ #category : #'interface_b' }
ImplementsB >> methodB [
	Transcript show: 'methodB desde ImplementsB'
]
