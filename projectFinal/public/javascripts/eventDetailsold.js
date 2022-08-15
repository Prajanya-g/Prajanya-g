  var vueinst = new Vue({
    el: '#account',
    mounted:function(){
        this.loading() //method1 will execute at pageload
        this.eventName = this.eventDetails;
    },
    data: {
        months: [],
        datesInMonths: [],
        dates: [],
        name:'Enter Name',
        newParticipant: false,
        eventName: '',
        email: '',
        finalDate: '',
        available: false,
        final: false,
        participantButton: true,
        finalise: false,
        date: false,
        done:false,
        host: false,
        currentSelected: [],
        other:[],
    },
    methods:{
        
    }
});